library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_logic_arith.ALL;

entity TestAfficheurRelatif is
end TestAfficheurRelatif;

architecture Behavioral of TestAfficheurRelatif is

    component AfficheurRelatif
        Port ( input : in STD_LOGIC_VECTOR (3 downto 0);
               negate : in STD_LOGIC;
               output : out STD_LOGIC_VECTOR (7 downto 0));
    end component;
    
    signal negate : STD_LOGIC;
    signal input : STD_LOGIC_VECTOR (3 downto 0);
    signal output : STD_LOGIC_VECTOR (7 downto 0);
    
    constant period:time:=10 ns;
    
begin
    process
        variable val : integer :=0;
    begin
        boucle: FOR val in 0 to 8 loop
            negate <= '0'; input <= conv_std_logic_vector(val,4); wait for period;
            negate <= '1'; input <= conv_std_logic_vector(val,4); wait for period;
        end loop;
        wait;     
    end process;
    
    Map_Complement : AfficheurRelatif PORT MAP(input, negate, output);
end Behavioral;
