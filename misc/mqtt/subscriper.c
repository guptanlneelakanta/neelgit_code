#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MQTTClient.h"

#define ADDRESS "tcp://test.mosquitto.org:1883"
#define CLIENTID "Client2"
#define TOPIC "test/topic"

void delivered(void *context, MQTTClient_deliveryToken dt) {}

int msgarrvd(void *context, char *topicName, int topicLen,
             MQTTClient_message *message) {
    printf("Received: %.*s\n",   message->payloadlen, (char*)message->payload);

    MQTTClient_freeMessage(&message);
    MQTTClient_free(topicName);
    return 1;
}

int main() {
    MQTTClient client;
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;

    MQTTClient_create(&client, ADDRESS, CLIENTID,
                      MQTTCLIENT_PERSISTENCE_NONE, NULL);

    MQTTClient_setCallbacks(client, NULL, NULL, msgarrvd, NULL);

    MQTTClient_connect(client, &conn_opts);
    MQTTClient_subscribe(client, TOPIC, 1);

    printf("Waiting for messages...\n");
    while(1);

    return 0;
}


