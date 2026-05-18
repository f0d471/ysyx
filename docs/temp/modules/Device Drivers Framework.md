# Device Drivers Framework

## Purpose

The Device Drivers Framework provides a unified, abstracted interface for hardware peripheral drivers in RT-Thread RTOS. It enables application developers to interact with diverse hardware devices through a consistent API, while allowing driver developers to implement hardware-specific logic behind a standardized operations structure.

## Architecture

The framework follows a layered object-oriented design pattern. Each device type is represented by a **device class** (e.g., `rt_serial_device`, `rt_i2c_bus_device`) that inherits from the base `rt_device` structure. Each class contains a pointer to an **operations structure** (e.g., `rt_uart_ops`, `rt_i2c_bus_device_ops`) which defines the hardware-specific callbacks. Drivers register themselves with the system using registration APIs, and applications access devices through the standard `rt_device_open/close/read/write/ioctl` interface. This separation of interface and implementation allows for easy portability and driver reuse.

## Key Components

### Serial/UART Driver
The serial device model (`rt_serial_device`) wraps UART hardware. It uses `rt_uart_ops` for operations like configure, send, receive, and control flow. The `serial_configure` structure holds baud rate, data bits, parity, and stop bits. Internal FIFO buffers (`rt_serial_rx_fifo`, `rt_serial_tx_fifo`) manage interrupt-driven data transfer.

### I2C Driver
The I2C bus device (`rt_i2c_bus_device`) manages multi-master I2C communication. `rt_i2c_bus_device_ops` provides master_xfer and slave_xfer callbacks. Messages are represented by `rt_i2c_msg` with flags for read/write direction and start/stop conditions. Bit-banging support is provided via `rt_i2c_bit_ops`.

### SPI Driver
SPI devices (`rt_spi_device`) attach to an SPI bus (`rt_spi_bus`). The `rt_spi_ops` structure handles bus configuration and data transfer. `rt_spi_message` supports multi-segment transfers with CS control. `rt_spi_configuration` defines mode, data width, and clock speed.

### GPIO/Pin Driver
The pin device (`rt_device_pin`) provides a generic GPIO interface. `rt_pin_ops` defines operations for mode setting, value read/write, and interrupt handling. `rt_device_pin_mode` and `rt_device_pin_value` are used with the ioctl interface. `rt_pin_irq_hdr` is the callback type for pin interrupts.

### CAN Driver
The CAN device (`rt_can_device`) supports both standard and extended frame formats. `rt_can_ops` includes send, receive, and filter configuration. `rt_can_msg` carries ID, data, and flags. `rt_can_filter_item` and `rt_can_filter_config` manage hardware acceptance filters.

### ADC/DAC Driver
ADC (`rt_adc_device`) and DAC (`rt_dac_device`) share a similar pattern. Their ops structures (`rt_adc_ops`, `rt_dac_ops`) provide enable/disable and read/write channel operations. Channels are typically configured via ioctl.

### PWM Driver
The PWM device (`rt_device_pwm`) uses `rt_pwm_ops` for channel configuration. `rt_pwm_configuration` specifies period, pulse width, and polarity. Multiple channels per device are supported.

### Hardware Timer Driver
The hardware timer (`rt_hwtimer_device`) provides precise timing. `rt_hwtimer_ops` includes start, stop, count get/set, and callback registration. `rt_hwtimer_info` describes capabilities (resolution, frequency). `rt_hwtimerval` represents time values. Low-power timers (`rt_lptimer`) are also supported.

### RTC & Alarm
The RTC device (`rt_rtc_device`) maintains system time. `rt_rtc_ops` provides get/set time and alarm operations. `rt_rtc_wkalarm` configures wake-up alarms. `rt_alarm` is a higher-level alarm abstraction that can trigger callbacks.

### Watchdog Driver
The watchdog device (`rt_watchdog_device`) prevents system hangs. `rt_watchdog_ops` includes start, stop, and feed (kick) operations. Timeout values are configured via ioctl.

### Sensor & Touch Driver
The sensor framework (`rt_sensor_device`) supports various sensor types (accelerometer, gyroscope, temperature, etc.). `rt_sensor_ops` handles data fetching and configuration. `rt_sensor_info` describes sensor capabilities. `rt_sensor_data` provides standardized data output. `rt_sensor_config` allows per-sensor parameter tuning.

### Audio Driver
The audio device (`rt_audio_device`) manages audio playback and capture. `rt_audio_ops` includes setup, start, stop, and buffer management. `rt_audio_caps` describes hardware capabilities. `rt_audio_configure` sets sample rate, channels, and format. `rt_audio_buf_info` manages audio buffer descriptors.

### Flash/MTD Driver
Memory Technology Device (MTD) drivers support NAND (`rt_mtd_nand_device`) and NOR (`rt_mtd_nor_device`) flash. Their ops structures (`rt_mtd_nand_driver_ops`, `rt_mtd_nor_driver_ops`) provide read, write, erase, and bad block management.

### SD/MMC Driver
The SD/MMC stack includes host controller (`rt_mmcsd_host`), card (`rt_mmcsd_card`), and protocol structures. `rt_mmcsd_host_ops` handles command/response and data transfer. `rt_mmcsd_cmd` and `rt_mmcsd_data` represent SD protocol transactions.

### Ethernet/PHY Driver
The PHY device (`rt_phy_device`) manages physical layer transceivers. `rt_phy_ops` provides link status, speed/duplex negotiation. The MDIO bus (`rt_mdio_bus`) with `rt_mdio_bus_ops` handles register-level PHY access. `rt_phy_msg` carries PHY management frames.

### Hardware Crypto Driver
The hardware crypto framework (`rt_hwcrypto_device`) accelerates cryptographic operations. `rt_hwcrypto_ops` provides context management and operation callbacks. Specialized sub-modules include hash (`hwcrypto_hash`, `hwcrypto_hash_ops`), symmetric ciphers, and asymmetric operations (e.g., `hw_bignum_mpi` for big number math).

### Power Management
The power management subsystem (`rt_pm`) coordinates system-wide power states. `rt_pm_ops` defines state transitions and device suspend/resume. `rt_pm_module` allows per-module power control. `rt_pm_notify` provides state change callbacks. `rt_device_pm` integrates device-level power management.

## Design Pattern

All device drivers in this framework follow a consistent pattern:

1. **Device Structure**: Each driver type defines a device struct (e.g., `rt_serial_device`) that embeds the base `rt_device` and adds type-specific fields.

2. **Operations Interface**: A separate ops struct (e.g., `rt_uart_ops`) contains function pointers for hardware-specific operations. This allows multiple implementations of the same device type.

3. **Registration**: Drivers call a type-specific registration function (e.g., `rt_hw_serial_register()`) to add the device to the system's device list.

4. **Standard Lifecycle**: Applications interact through the generic device API:
   - `rt_device_open()` - Initialize and prepare the device
   - `rt_device_read()` / `rt_device_write()` - Data transfer
   - `rt_device_control()` - Configuration via ioctl commands
   - `rt_device_close()` - Release and power-down

5. **Configuration**: Device-specific parameters are passed through configuration structs (e.g., `serial_configure`) via the ioctl interface, maintaining type safety while keeping the generic API clean.

This pattern ensures that application code remains portable across different hardware platforms, while driver developers have clear interfaces to implement.