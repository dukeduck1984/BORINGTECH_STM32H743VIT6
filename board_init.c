/*
#include "py/mphal.h"

void NUCLEO_H743ZI_board_early_init(void) {
    // Turn off the USB switch
    #define USB_PowerSwitchOn pin_G6
    mp_hal_pin_output(USB_PowerSwitchOn);
    mp_hal_pin_low(USB_PowerSwitchOn);
}
*/

#include "storage.h"
#include "qspi.h"

// This configuration is needed for mboot to be able to write to the external QSPI flash

STATIC mp_spiflash_cache_t spi_bdev_cache;

const mp_spiflash_config_t spiflash_config = {
    .bus_kind = MP_SPIFLASH_BUS_QSPI,
    .bus.u_qspi.data = NULL,
    .bus.u_qspi.proto = &qspi_proto,
    .cache = &spi_bdev_cache,
};

spi_bdev_t spi_bdev;

// This init function is needed to memory map the QSPI flash early in the boot process

void board_early_init(void) {
    qspi_init();
    qspi_memory_map();
}
