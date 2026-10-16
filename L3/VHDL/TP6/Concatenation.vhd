library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Concatenation is
    Port ( a : in STD_LOGIC_VECTOR (3 downto 0);
           b : in STD_LOGIC_VECTOR (3 downto 0);
           led : out STD_LOGIC_VECTOR (7 downto 0));
end Concatenation;

architecture Behavioral of Concatenation is

begin
    process(a, b)
        variable val : integer :=0;
    begin
        boucle: FOR val in 0 to 3 loop
            led(val) <= a(val);
            led(val + 4) <= b(val);
        end loop;
    end process;
end Behavioral;