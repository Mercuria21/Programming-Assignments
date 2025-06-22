#include <dpp/dpp.h>
#include <cstdlib>

const std::string TOKEN = "EVE4zhDpZfiwVXoBvGZlqzcssQGC5Rrh";

int main() {
    dpp::cluster bot(std::getenv(TOKEN));
    bot.on_message_create([](const dpp::message_create_t& event) {
        if (event.msg.content == "Hello" || event.msg.content == "hello") {
            event.msg.reply("Diam lancau");
        }
        else if (event.msg.content == "Nigga" || event.msg.content == "nigga") {
            event.msg.reply("You are");
        }
    });
    bot.start(dpp::st_wait);
    return 0;
}