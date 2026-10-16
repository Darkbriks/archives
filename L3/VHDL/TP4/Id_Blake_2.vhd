library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- (!a+b).(a+c)  = !a.c + a.b
entity Id_Blake_2 is
    Port ( a : in STD_LOGIC;
           b : in STD_LOGIC;
           c : in STD_LOGIC;
           res : out STD_LOGIC);
end Id_Blake_2;

architecture Behavioral of Id_Blake_2 is

begin
    res<= ((not a) and c) or (a and b);
end Behavioral;