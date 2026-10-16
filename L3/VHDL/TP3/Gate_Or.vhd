library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Gate_Or is
    Port ( e1 : in STD_LOGIC;
           e2 : in STD_LOGIC;
           res : out std_logic);
end Gate_Or;

architecture Behavioral of Gate_Or is

begin
    res<='1' when e1='1' or e2='1' else '0';
end Behavioral;
