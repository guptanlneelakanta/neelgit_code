#include <stdio.h>
#include <string.h>
#include "MQTTClient.h"

#define ADDRESS "tcp://test.mosquitto.org:1883"
#define CLIENTID "Client1"
#define TOPIC "test/topic"
#define PAYLOAD "Hello from device"
#define QOS 1

int main() {
    MQTTClient client;
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    MQTTClient_message pubmsg = MQTTClient_message_initializer;
    MQTTClient_deliveryToken token;

    MQTTClient_create(&client, ADDRESS, CLIENTID,
                      MQTTCLIENT_PERSISTENCE_NONE, NULL);

    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;

    MQTTClient_connect(client, &conn_opts);

    pubmsg.payload = PAYLOAD;
    pubmsg.payloadlen = strlen(PAYLOAD);
    pubmsg.qos = QOS;

    MQTTClient_publishMessage(client, TOPIC, &pubmsg, &token);
    MQTTClient_waitForCompletion(client, token, 1000);

    printf("Message sent: %s\n", PAYLOAD);

    MQTTClient_disconnect(client, 1000);
    MQTTClient_destroy(&client);

    return 0;
}