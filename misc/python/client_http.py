# client.py


import ssl
import urllib.request

url = "https://localhost:4443/"
context = ssl._create_unverified_context()  # skip verification for demo

with urllib.request.urlopen(url, context=context) as response:
    print("Response:", response.read().decode())

