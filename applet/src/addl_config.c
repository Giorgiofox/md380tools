/*! \file addl_config.c
  \brief .
*/

#include <stdio.h>
#include <string.h>

#include "printf.h"
#include "dmesg.h"
#include "md380.h"
#include "version.h"
#include "config.h"
#include "printf.h"
#include "spiflash.h"


struct addl_config {
  uint8_t  rbeep;
  uint8_t  datef;
  uint8_t  userscsv;
  uint8_t  debug;
  uint8_t  promtg;
  } global_addl_config;

void init_global_addl_config_hook(void) {
  int8_t buf[1];

  spiflash_read(buf, spi_flash_addl_config_start + offset_rbeep, 1);
  if (buf[0] == '1') {
    global_addl_config.rbeep = 1;
  } else {
    global_addl_config.rbeep = 0;
  }

  spiflash_read(buf, spi_flash_addl_config_start + offset_datef, 1);
  if (buf[0] == '1') {
    global_addl_config.datef = 1;
  } else {
    global_addl_config.datef = 0;
  }

  spiflash_read(buf, spi_flash_addl_config_start + offset_userscsv, 1);
  if (buf[0] == '1') {
    global_addl_config.userscsv = 1;
  } else {
    global_addl_config.userscsv = 0;
  }

  spiflash_read(buf, spi_flash_addl_config_start + offset_debug, 1);
  if (buf[0] == '1') {
    global_addl_config.debug = 1;
  } else {
    global_addl_config.debug = 0;
  }

  spiflash_read(buf, spi_flash_addl_config_start + offset_promtg, 1);
  if (buf[0] == '1') {
    global_addl_config.promtg=1;
  } else {
    global_addl_config.promtg=0;
  }
  // hooked call
  md380_create_main_meny_entry();
}
