#include <iostream>
#include "mqtt/async_client.h"

using namespace std;

const string ADDRESS = "tcp://test.mosquitto.org:1883";
const string CLIENT_ID = "cpp_subscriber";
const string TOPIC = "test/iot/demo";
const int QOS = 1;

int main() {
    mqtt::async_client client(ADDRESS, CLIENT_ID);

    client.connect()->wait();
    client.start_consuming();
    client.subscribe(TOPIC, QOS)->wait();

    cout << "Subscribed to topic: " << TOPIC << endl;

    while (true) {
        auto msg = client.consume_message();
        if (msg) {
            cout << "Received: " << msg->to_string() << endl;
        }
    }

    client.disconnect()->wait();
    return 0;
}
