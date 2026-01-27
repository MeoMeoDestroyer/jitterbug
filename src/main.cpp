#include <bn_core.h>
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_random.h>
#include <bn_keypad.h>
#include <bn_vector.h>
#include <bn_fixed_point.h>
#include <bn_sprite_ptr.h>

#include "bn_sprite_items_worm.h"

int main()
{
    bn::core::init();

    bn::random rng;

    bn::backdrop::set_color(bn::color(31, 9, 24));

    bn::vector<bn::sprite_ptr, 16> worms;

    while(true)
    {
        // Move existing worms randomly
        for(bn::sprite_ptr& worm : worms)
        {
            bn::fixed new_x = worm.x() + rng.get_fixed(-1, 1);   // [-1, 1)
            bn::fixed new_y = worm.y() + rng.get_fixed(-1, 1);   // [-1, 1)

            worm.set_x(new_x);
            worm.set_y(new_y);
        }

        // Spawn a new worm when A pressed
        if(bn::keypad::a_pressed())
        {
            if(worms.full())
            {
                // optional: do nothing or overwrite an old one
            }
            else
            {
                // Give the new worm a starting position (center of screen)
                bn::sprite_ptr new_worm = bn::sprite_items::worm.create_sprite(0, 0);
                worms.push_back(bn::move(new_worm));
            }
        }

        bn::core::update();
    }
}