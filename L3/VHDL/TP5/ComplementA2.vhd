library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;

entity ComplementA2 is
    Port ( input : in STD_LOGIC_VECTOR (3 downto 0);
           output : out STD_LOGIC_VECTOR (3 downto 0));
end ComplementA2;

architecture Behavioral of ComplementA2 is
    component ComplementA1
        Port ( input : in STD_LOGIC_VECTOR (3 downto 0);
               output : out STD_LOGIC_VECTOR (3 downto 0));
    end component;
    
    signal complement_a_1 : STD_LOGIC_VECTOR (3 downto 0);
begin
    Mapping : ComplementA1 PORT MAP(input, complement_a_1);
    output <= complement_a_1 + "0001";
end Behavioral;