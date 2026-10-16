library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity AfficheurRelatif is
    Port ( input : in STD_LOGIC_VECTOR (3 downto 0);
           negate : in STD_LOGIC;
           output : out STD_LOGIC_VECTOR (7 downto 0));
end AfficheurRelatif;

architecture Behavioral of AfficheurRelatif is
begin
    process(input, negate)
    begin
        if input = "0000" then output <= "00000011"; -- 0
        elsif input = "0001" then output <= "10011111"; -- 1
        elsif input = "0010" then output <= "00100101"; -- 2
        elsif input = "0011" then output <= "00001101"; -- 3
        elsif input = "0100" then output <= "10011001"; -- 4
        elsif input = "0101" then output <= "01001001"; -- 5
        elsif input = "0110" then output <= "01000001"; -- 6
        elsif input = "0111" then output <= "00011111"; -- 7
        elsif input = "1000" then output <= "00000001"; -- 8
        end if;

        output(0) <= not negate;
    end process;
end Behavioral;