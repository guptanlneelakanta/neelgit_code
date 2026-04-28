#include <rte_eal.h>
#include <rte_ethdev.h>

int main(int argc, char **argv)
{
    rte_eal_init(argc, argv);

    uint16_t port_id = 0;
    struct rte_mbuf *bufs[32];

    while (1) {
        uint16_t nb_rx = rte_eth_rx_burst(port_id, 0, bufs, 32);

        for (int i = 0; i < nb_rx; i++) {
            // Process packet
            rte_eth_tx_burst(port_id, 0, &bufs[i], 1);
        }
    }
}