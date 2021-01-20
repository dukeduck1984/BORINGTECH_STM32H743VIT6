#define MICROPY_HW_BOARD_NAME       "Boring_TECH STM32H743"
#define MICROPY_HW_MCU_NAME         "STM32H743VIT6"

#define MICROPY_PY_PYB_LEGACY       (0)
#define MICROPY_HW_ENABLE_RTC       (1)
#define MICROPY_HW_ENABLE_RNG       (1)
#define MICROPY_HW_ENABLE_ADC       (1)
#define MICROPY_HW_ENABLE_DAC       (1)
#define MICROPY_HW_ENABLE_TIMER     (1)
#define MICROPY_HW_ENABLE_USB       (1)
#define MICROPY_HW_ENABLE_SDCARD    (1)  // it has a sd card, but no detect pin
#define MICROPY_HW_HAS_SWITCH       (1)
#define MICROPY_HW_HAS_FLASH        (1)

/*
#define MICROPY_BOARD_EARLY_INIT    board_early_init
void board_early_init(void);
*/

// The board has an 8MHz HSE, the following gives 480MHz CPU speed
// VCOClock = HSE * PLLN / PLLM = 8 MHz * 480 / 4 = 960 MHz
// SYSCLK = VCOClock / PLLP = 960 MHz / 2 = 480 MHz
#define MICROPY_HW_CLK_PLLM         (4)
#define MICROPY_HW_CLK_PLLN         (480)
#define MICROPY_HW_CLK_PLLP         (2)
#define MICROPY_HW_CLK_PLLQ         (4)
#define MICROPY_HW_CLK_PLLR         (2)

// The USB clock is set using PLL3
#define MICROPY_HW_CLK_PLL3M        (4)
#define MICROPY_HW_CLK_PLL3N        (120)
#define MICROPY_HW_CLK_PLL3P        (2)
#define MICROPY_HW_CLK_PLL3Q        (5)
#define MICROPY_HW_CLK_PLL3R        (2)

// RTC
// LSE external crystal is 32768 Hz.
// --OK
#define MICROPY_HW_RTC_USE_LSE      (1)
#define MICROPY_HW_RTC_USE_US       (0)

// 4 wait states
#define MICROPY_HW_FLASH_LATENCY    FLASH_LATENCY_4

// UART config
// --OK
#define MICROPY_HW_UART1_TX         (pin_A9)
#define MICROPY_HW_UART1_RX         (pin_A10)
#define MICROPY_HW_UART2_TX         (pin_D5)
#define MICROPY_HW_UART2_RX         (pin_D6)
#define MICROPY_HW_UART3_TX         (pin_D8)
#define MICROPY_HW_UART3_RX         (pin_D9)
#define MICROPY_HW_UART4_TX         (pin_D1)
#define MICROPY_HW_UART4_RX         (pin_D0)
#define MICROPY_HW_UART7_TX         (pin_E8)
#define MICROPY_HW_UART7_RX         (pin_E7)
#define MICROPY_HW_UART8_TX         (pin_E1)
#define MICROPY_HW_UART8_RX         (pin_E0)

#define MICROPY_HW_UART_REPL        PYB_UART_3
#define MICROPY_HW_UART_REPL_BAUD   115200

// I2C buses
// --OK
#define MICROPY_HW_I2C1_SCL         (pin_B6)
#define MICROPY_HW_I2C1_SDA         (pin_B7)
#define MICROPY_HW_I2C4_SCL         (pin_B8)
#define MICROPY_HW_I2C4_SDA         (pin_B9)

// SPI buses
// --OK
#define MICROPY_HW_SPI1_NSS         (pin_A4)
#define MICROPY_HW_SPI1_SCK         (pin_A5)
#define MICROPY_HW_SPI1_MISO        (pin_A6)
#define MICROPY_HW_SPI1_MOSI        (pin_A7)
#define MICROPY_HW_SPI2_NSS         (pin_B12)
#define MICROPY_HW_SPI2_SCK         (pin_B13)
#define MICROPY_HW_SPI2_MISO        (pin_B14)
#define MICROPY_HW_SPI2_MOSI        (pin_B15)
#define MICROPY_HW_SPI4_NSS         (pin_E11)
#define MICROPY_HW_SPI4_SCK         (pin_E12)
#define MICROPY_HW_SPI4_MISO        (pin_E13)
#define MICROPY_HW_SPI4_MOSI        (pin_E14)
#define MICROPY_HW_SPI6_NSS         (pin_A15)
#define MICROPY_HW_SPI6_SCK         (pin_B3)
#define MICROPY_HW_SPI6_MISO        (pin_B4)
#define MICROPY_HW_SPI6_MOSI        (pin_B5)

// USRSW has no pullup or pulldown. Pressing the button makes the input go low.
// --OK
#define MICROPY_HW_USRSW_PIN        (pin_C13)
#define MICROPY_HW_USRSW_PULL       (GPIO_PULLUP)
#define MICROPY_HW_USRSW_EXTI_MODE  (GPIO_MODE_IT_FALLING)
#define MICROPY_HW_USRSW_PRESSED    (0)

// LEDs
// The RGB Led is common anode, so is active low.
// --OK
#define MICROPY_HW_LED1             (pin_C0)   // red
#define MICROPY_HW_LED2             (pin_C1)   // green
#define MICROPY_HW_LED3             (pin_C2)   // blue
#define MICROPY_HW_LED_ON(pin)      (mp_hal_pin_low(pin))
#define MICROPY_HW_LED_OFF(pin)     (mp_hal_pin_high(pin))

/*
// Winbond W25Q64 external SPI Flash = 64 Mbit (8 Mbyte)
#define MICROPY_HW_SPIFLASH_SIZE_BITS (64 * 1024 * 1024)
#define MICROPY_HW_SPIFLASH_CS        (pin_B12)
#define MICROPY_HW_SPIFLASH_SCK       (pin_B13)
#define MICROPY_HW_SPIFLASH_MISO      (pin_B14)
#define MICROPY_HW_SPIFLASH_MOSI      (pin_B15)
*/

// Winbond W25Q64 external QSPI Flash = 64 Mbit (8 Mbyte)
// --OK
#define MICROPY_HW_QSPIFLASH_SIZE_BITS_LOG2 (26)
#define MICROPY_HW_QSPIFLASH_CS       (pin_B10)
#define MICROPY_HW_QSPIFLASH_SCK      (pin_B2)
#define MICROPY_HW_QSPIFLASH_IO0      (pin_D11)
#define MICROPY_HW_QSPIFLASH_IO1      (pin_D12)
#define MICROPY_HW_QSPIFLASH_IO2      (pin_E2)
#define MICROPY_HW_QSPIFLASH_IO3      (pin_A1)

// SPI flash, block device config (for use as filesystem)
// --OK
extern const struct _mp_spiflash_config_t spiflash_config;
extern struct _spi_bdev_t spi_bdev;
//#if !USE_QSPI_XIP
// If using onboard SPI Flash
// 1 = use internal flash (2 MByte)
// 0 = use onboard SPI flash (8 MByte) Winbond W25Q64
#define MICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE (0)
//#define MICROPY_HW_SPIFLASH_ENABLE_CACHE (1)
#define MICROPY_HW_BDEV_IOCTL(op, arg) ( \
    (op) == BDEV_IOCTL_NUM_BLOCKS ? ((1 << MICROPY_HW_QSPIFLASH_SIZE_BITS_LOG2) / 8 / FLASH_BLOCK_SIZE) : \
    (op) == BDEV_IOCTL_INIT ? spi_bdev_ioctl(&spi_bdev, (op), (uint32_t)&spiflash_config) : \
    spi_bdev_ioctl(&spi_bdev, (op), (arg)) \
)
#define MICROPY_HW_BDEV_READBLOCKS(dest, bl, n) spi_bdev_readblocks(&spi_bdev, (dest), (bl), (n))
#define MICROPY_HW_BDEV_WRITEBLOCKS(src, bl, n) spi_bdev_writeblocks(&spi_bdev, (src), (bl), (n))
#define MICROPY_HW_BDEV_SPIFLASH_EXTENDED (&spi_bdev) // for extended block protocol
//#endif

// USB config
// --OK
#define MICROPY_HW_USB_FS           (1)
//#define MICROPY_HW_USB_HS           (0)
//#define MICROPY_HW_USB_CDC_NUM      (2)
//#define MICROPY_HW_USB_MSC          (0)
//#define MICROPY_HW_USB_VBUS_DETECT_PIN (pin_A9)
//#define MICROPY_HW_USB_OTG_ID_PIN      (pin_A10)

// FDCAN bus
// --OK
#define MICROPY_HW_CAN1_NAME  "FDCAN1"
#define MICROPY_HW_CAN1_TX    (pin_D1)
#define MICROPY_HW_CAN1_RX    (pin_D0)

// SD Card
// --OK
#define MICROPY_HW_SDMMC_D0                 (pin_C8)
#define MICROPY_HW_SDMMC_D1                 (pin_C9)
#define MICROPY_HW_SDMMC_D2                 (pin_C10)
#define MICROPY_HW_SDMMC_D3                 (pin_C11)
#define MICROPY_HW_SDMMC_CK                 (pin_C12)
#define MICROPY_HW_SDMMC_CMD                (pin_D2)

// SD card detect switch
// --OK
#define MICROPY_HW_SDCARD_DETECT_PIN        (pyb_pin_SD_SW) // dummy, no switch at this pin
                                                            // needs to pull low manually
#define MICROPY_HW_SDCARD_DETECT_PULL       (GPIO_PULLUP)
#define MICROPY_HW_SDCARD_DETECT_PRESENT    (GPIO_PIN_RESET)

// Ethernet via RMII (MDC define disabled for now until eth.c supports H7)
//#define MICROPY_HW_ETH_MDC          (pin_C1)
/*
#define MICROPY_HW_ETH_MDIO         (pin_A2)
#define MICROPY_HW_ETH_RMII_REF_CLK (pin_A1)
#define MICROPY_HW_ETH_RMII_CRS_DV  (pin_A7)
#define MICROPY_HW_ETH_RMII_RXD0    (pin_C4)
#define MICROPY_HW_ETH_RMII_RXD1    (pin_C5)
#define MICROPY_HW_ETH_RMII_TX_EN   (pin_G11)
#define MICROPY_HW_ETH_RMII_TXD0    (pin_G13)
#define MICROPY_HW_ETH_RMII_TXD1    (pin_B13)
*/

/******************************************************************************/
// Bootloader configuration

/*
#define MBOOT_FSLOAD                (0)

// configure pin to force entry into the boot loader
#define MBOOT_BOOTPIN_PIN           (pyb_pin_USRSW)
#define MBOOT_BOOTPIN_PULL          (MP_HAL_PIN_PULL_UP)
#define MBOOT_BOOTPIN_ACTIVE        (0)

// Give Mboot access to the external QSPI flash
#define MBOOT_SPIFLASH_ADDR                     (0x90000000)
#define MBOOT_SPIFLASH_BYTE_SIZE                (64 * 128 * 1024)
#define MBOOT_SPIFLASH_LAYOUT                   "/0x90000000/64*64Kg"
#define MBOOT_SPIFLASH_ERASE_BLOCKS_PER_PAGE    (64 / 4) // 64k page, 4k erase block
#define MBOOT_SPIFLASH_CONFIG                   (&spiflash_config)
#define MBOOT_SPIFLASH_SPIFLASH                 (&spi_bdev.spiflash)

// To enable loading firmware from a filesystem
#define MBOOT_FSLOAD (1)
#define MBOOT_VFS_LFS2 (1)
*/
