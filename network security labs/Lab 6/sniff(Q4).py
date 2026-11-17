#!/usr/bin/python3
from scapy.all import *

def show_packet(pkt):
    if pkt.haslayer(ICMP):
        icmp_type = pkt[ICMP].type
        if icmp_type == 0:  # echo-reply
            print(f"Echo-reply from: {pkt[IP].src}")
        elif icmp_type == 8:  # echo-request
            print(f"Echo-request from: {pkt[IP].src}")

sniff(iface="eth0", filter="icmp", prn=show_packet)