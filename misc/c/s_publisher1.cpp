#include <iostream>
#include "mqtt/async_client.h"

using namespace std;

const string ADDRESS = "tcp://test.mosquitto.org:1883";
const string CLIENT_ID = "cpp_publisher";
const string TOPIC = "test/iot/demo";
const int QOS = 1;

int main() {
    mqtt::async_client client(ADDRESS, CLIENT_ID);

    client.connect()->wait();

    string payload = "Hello MQTT from C++";
    auto msg = mqtt::make_message(TOPIC, payload);
    msg->set_qos(QOS);

    client.publish(msg)->wait();
    cout << "Message published" << endl;

    client.disconnect()->wait();
    return 0;
}
