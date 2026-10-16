library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Gate_Not is
    Port ( e : in STD_LOGIC;
           res : out std_logic); -- 1 = True
end Gate_Not;

architecture Behavioral of Gate_Not is

begin
    res<='1' when e = '0' else '0';
end Behavioral;