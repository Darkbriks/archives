library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity ComplementA1 is
    Port ( input : in STD_LOGIC_VECTOR (3 downto 0);
           output : out STD_LOGIC_VECTOR (3 downto 0));
end ComplementA1;

architecture Behavioral of ComplementA1 is

begin
    output <= not input;
end Behavioral;