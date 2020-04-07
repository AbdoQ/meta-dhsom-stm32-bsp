DEFAULTTUNE ?= "cortexa7thf-neon-vfpv4"
SOC_FAMILY ?= "stm32mp1"

ARM_INSTRUCTION_SET = "thumb"

require conf/machine/include/tune-cortexa7.inc
require conf/machine/include/soc-family.inc

MACHINE_FEATURES ?= "apm alsa ext2 keyboard screen serial touchscreen usbgadget usbhost"

SERIAL_CONSOLE = "115200 ttySTM0"

# U-Boot bootloader
UBOOT_ENTRYPOINT := "0xc4000000"
UBOOT_MAKE_TARGET := "u-boot.itb all"
UBOOT_BINARY := "u-boot.itb"
UBOOT_SUFFIX ?= "itb"
SPL_BINARY := "u-boot-spl.stm32"
UBOOT_ENV = "boot"
UBOOT_ENV_SUFFIX = "scr"

PREFERRED_PROVIDER_virtual/bootloader = "u-boot-mainline"
PREFERRED_PROVIDER_u-boot = "u-boot-mainline"
PREFERRED_PROVIDER_u-boot-native = "u-boot-mainline"
PREFERRED_PROVIDER_u-boot-fw-utils = "u-boot-mainline-fw-utils"
PREFERRED_PROVIDER_u-boot-fw-utils-native = "u-boot-mainline-fw-utils-native"
PREFERRED_VERSION_u-boot = "2020.04%"
PREFERRED_VERSION_u-boot-native = "2020.04%"
PREFERRED_VERSION_u-boot-fw-utils = "2020.04%"
PREFERRED_VERSION_u-boot-fw-utils-native = "2020.04%"

# Linux kernel
KERNEL_IMAGETYPE = "fitImage"
KERNEL_CLASSES += " kernel-fitimage "
KERNEL_MODULES_AUTOLOAD += " etnaviv "

PREFERRED_PROVIDER_virtual/kernel = "linux-stable"
PREFERRED_VERSION_linux-yocto = "5.4%"

# Mesa
PREFERRED_PROVIDER_virtual/egl ?= "mesa-mainline"
PREFERRED_PROVIDER_virtual/libgl ?= "mesa-mainline"
PREFERRED_PROVIDER_virtual/libgl-native ?= "mesa-mainline-native"
PREFERRED_PROVIDER_virtual/nativesdk-libgl ?= "nativesdk-mesa-mainline"
PREFERRED_PROVIDER_virtual/libgles1 ?= "mesa-mainline"
PREFERRED_PROVIDER_virtual/libgles2 ?= "mesa-mainline"
PREFERRED_PROVIDER_virtual/mesa ?= "mesa-mainline"
PREFERRED_PROVIDER_nativesdk-mesa ?= "nativesdk-mesa-mainline"

# Ship kernel modules
MACHINE_ESSENTIAL_EXTRA_RDEPENDS += " kernel-modules kernel-devicetree u-boot-default-env "

# List of images to be built
IMAGE_FSTYPES ?= "tar.xz wic.xz"
INITRAMFS_FSTYPES ?= "cpio.xz"

EXTRA_IMAGEDEPENDS += "virtual/bootloader"
WKS_FILE = "sdimage-stm32mp1.wks"
IMAGE_BOOT_FILES ?= "${KERNEL_IMAGETYPE}"
IMAGE_INSTALL_append = " kernel-devicetree kernel-image-fitimage u-boot-mainline "
do_image_wic[depends] += "mtools-native:do_populate_sysroot dosfstools-native:do_populate_sysroot virtual/bootloader:do_deploy"