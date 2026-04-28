Step 2 – Generate a self-signed certificate

Use OpenSSL (already installed on Mint) to create a temporary certificate:

openssl req -x509 -newkey rsa:2048 -nodes -keyout server.key -out server.crt -days 365


You’ll see prompts like Country Name, Common Name, etc.
For Common Name, type localhost.

This command generates:

server.key – private key

server.crt – certificate

▶️ Step 3 – Run the HTTPS server

Now start the server:

python3 server.py


Expected output:

Serving HTTPS on port 4443


Keep it running.

💻 Step 4 – Run the HTTPS client in another terminal

Open a new terminal and run:

python3 client.py


Expected output:

Response: Hello over HTTPS!


🎉 You have successfully made a secure HTTPS request from the client to the server.

🔎 Step 5 – (Optionally test via browser)

Open your web browser and go to:

https://localhost:4443/


You’ll likely see a certificate warning because it’s self-signed — click Advanced → Proceed to view “Hello over HTTPS!”.

🧠 Notes & Next Steps

For real deployments, replace the self-signed certificate with a trusted one (e.g., via Let’s Encrypt or your organization’s CA).

To enable proper verification on the client:

context = ssl.create_default_context(cafile="server.crt")


This tells the client to trust only that cert.

You can run both scripts on Raspberry Pi exactly the same way.
