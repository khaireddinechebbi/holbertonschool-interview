#!/usr/bin/env ruby

$global = "omg"

class Mona
    def instance_method
        p "see ? #{$global}, told you, look => #{$another}"
    end
    def self.class_method
        $another = "whattt ??"
        p "#{$global} #{$another}"
    end
end

Mona.class_method
monia = Mona.new
monia.instance_method