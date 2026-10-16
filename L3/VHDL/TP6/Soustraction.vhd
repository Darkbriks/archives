library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;

entity Soustraction is
    Port ( a : in STD_LOGIC_VECTOR (3 downto 0);
           b : in STD_LOGIC_VECTOR (3 downto 0);
           output : out STD_LOGIC_VECTOR (3 downto 0));
end Soustraction;

architecture Behavioral of Soustraction is
    component ComplementA2
        Port ( input : in STD_LOGIC_VECTOR (3 downto 0);
               output : out STD_LOGIC_VECTOR (3 downto 0));
    end component;
    
    signal complement_b : std_logic_vector (3 downto 0) := "0000";
begin
    Complement : ComplementA2 PORT MAP(b, complement_b);
    output <= a + complement_b;
end Behavioral;