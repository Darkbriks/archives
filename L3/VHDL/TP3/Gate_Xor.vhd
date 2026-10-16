library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Gate_Xor is
    Port ( e1 : in STD_LOGIC;
           e2 : in STD_LOGIC;
           res : out std_logic);
end Gate_Xor;

architecture Behavioral of Gate_Xor is

begin
    res<='1' when (not e1) = e2 else '0';
end Behavioral;
