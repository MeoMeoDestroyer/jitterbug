#include <bn_core.h>
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_sprite_ptr.h>

#include "bn_sprite_items_bug.h"

int main() {
    bn::core::init();

    bn::backdrop::set_color(bn::color(31, 0, 31));

    bn::sprite_ptr ladybug = bn::sprite_items::bug.create_sprite();

    while(true) {
        bn::core::update();
    }
}