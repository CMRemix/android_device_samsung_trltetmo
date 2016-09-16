#
# Copyright (C) 2014 The CyanogenMod Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

$(call inherit-product, device/samsung/trltetmo/full_trltetmo.mk)

# Enhanced NFC
$(call inherit-product, vendor/cm/config/nfc_enhanced.mk)

# Inherit common CM phone.
$(call inherit-product, vendor/cm/config/common_full_phone.mk)

PRODUCT_DEVICE := trltetmo
PRODUCT_NAME := cm_trltetmo
PRODUCT_BRAND := samsung
PRODUCT_MODEL := SM-N910T
PRODUCT_MANUFACTURER := samsung

# Set build fingerprint / ID / Product Name ect.
PRODUCT_BUILD_PROP_OVERRIDES += PRODUCT_NAME=trltetmo TARGET_DEVICE=trltetmo BUILD_FINGERPRINT="samsung/trltetmo/trltetmo:6.0.1/MMB29M/N910TUVS2EPG2:user/release-keys" PRIVATE_BUILD_DESC="trltetmo-user 6.0.1 MMB29M N910TUVS2EPG2 release-keys"

