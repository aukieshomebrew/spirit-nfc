file(GLOB SPIRIT_NFC_SRC "*.cpp" "base/*.cpp")

add_executable(spirit-nfc ${SPIRIT_NFC_SRC})
target_link_libraries(spirit-nfc 3ds::ctrulib)
