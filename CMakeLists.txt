cmake_minimum_required(VERSION 2.8)

project(spirit-nfc C CXX)


set(APP_TITLE "Spirit NFC")
set(APP_DESCRIPTION "Move like nothing happend.")
set(APP_AUTHOR "Homebrew Technics")
set(APP_ICON "res/spirit-nfc-logo.png")



set(RESOURCE_DIR "${CMAKE_SOURCE_DIR}/res")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${DKA_SUGGESTED_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${DKA_SUGGESTED_CXX_FLAGS}")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
include(Tools3DS)
find_package(CTRULIB REQUIRED)



add_subdirectory(src)


add_cia_target(spirit-nfc "res/spirit-nfc.rsf" "res/spirit-nfc-banner.png" "res/spirit-nfc.wav" "${APP_TITLE}" "${APP_DESCRIPTION}" "${APP_AUTHOR}" "${APP_ICON}" )
