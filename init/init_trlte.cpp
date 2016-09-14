/*
   Copyright (c) 2016, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include <cutils/properties.h>
#include "vendor_init.h"
#include "log.h"
#include "util.h"
#include <sys/system_properties.h>

#define ISMATCH(a,b)    (!strncmp(a,b,PROP_VALUE_MAX))

void gsm_properties()
{
    property_set("telephony.lteOnGsmDevice", "1");
    property_set("ro.telephony.default_network", "9");
}

void init_variant_properties() {
    char platform[PROP_VALUE_MAX];
    char bootloader[PROP_VALUE_MAX];
    char device[PROP_VALUE_MAX];
    char devicename[PROP_VALUE_MAX];
    int rc;

    rc = property_get("ro.board.platform", platform, NULL);
    if (!rc || !ISMATCH(platform, ANDROID_TARGET))
        return;

    property_get("ro.bootloader", bootloader, NULL);

    if (strstr(bootloader, "N910W8")) {
        /* trltecan These values are taken from TMO and edited for the 910W8 FIXME */
        property_set("ro.build.fingerprint", "samsung/trltevl/trltecan:6.0.1/MRA58K/N910TUVU2EPE3:user/release-keys");
        property_set("ro.build.description", "trltevl-user 6.0.1 MRA58K N910TUVU2EPE3 release-keys");
        property_set("ro.product.model", "SM-N910W8");
        property_set("ro.product.device", "trltecan");
        gsm_properties();
    } else {
        /* trltetmo */
        property_set("ro.build.fingerprint", "samsung/trltetmo/trltetmo:6.0.1/MRA58K/N910TUVU2EPE3:user/release-keys");
        property_set("ro.build.description", "trltetmo-user 6.0.1 MRA58K N910TUVU2EPE3 release-keys");
        property_set("ro.product.model", "SM-N910T");
        property_set("ro.product.device", "trltetmo");
        gsm_properties();
    }

    property_get("ro.product.device", device, NULL);
    strlcpy(devicename, device, sizeof(devicename));
    INFO("Found bootloader id %s setting build properties for %s device\n", bootloader, devicename);
}


void vendor_load_properties() {
    init_variant_properties();
}
