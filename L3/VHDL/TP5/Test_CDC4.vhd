library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_logic_arith.ALL;

entity Test_CDC4 is
end Test_CDC4;

architecture Behavioral of Test_CDC4 is

    component CDC4
        Port ( e1 : in STD_LOGIC_VECTOR (3 downto 0);
           bloc_afficheur : out STD_LOGIC_VECTOR (7 downto 0);
           led : out STD_LOGIC_VECTOR (3 downto 0));
    end component;
    
    signal input : STD_LOGIC_VECTOR (3 downto 0);
    signal output_leds : STD_LOGIC_VECTOR (3 downto 0);
    signal output_bloc : STD_LOGIC_VECTOR (7 downto 0);
    
    constant period:time:=10 ns;
    
begin
    process
        variable val : integer :=0;
    begin
        boucle: FOR val in 0 to 15 loop
            input <= conv_std_logic_vector(val,4);
            wait for period;
        end loop;
        wait;     
    end process;
    
    Mapping : CDC4 PORT MAP(input, output_bloc, output_leds);
end Behavioral;
