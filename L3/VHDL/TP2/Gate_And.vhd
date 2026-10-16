library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Gate_And is
    Port ( e1 : in STD_LOGIC;
           e2 : in STD_LOGIC;
           s : out std_logic);
end Gate_And;

architecture Behavioral of Gate_And is

begin
    s<='1' when e1='1' and e2='1' else '0';
end Behavioral;
