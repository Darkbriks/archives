library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- (a+b).(a+c)  = a + b.c
entity Id_Blake_1 is
    Port ( a : in STD_LOGIC;
           b : in STD_LOGIC;
           c : in STD_LOGIC;
           res : out STD_LOGIC);
end Id_Blake_1;

architecture Behavioral of Id_Blake_1 is

begin
    res<= a or (b and c);
end Behavioral;