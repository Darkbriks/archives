library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_logic_arith.ALL;

entity Test_CA1 is
end Test_CA1;

architecture Behavioral of Test_CA1 is

    component ComplementA1
        Port ( input : in STD_LOGIC_VECTOR (3 downto 0);
               output : out STD_LOGIC_VECTOR (3 downto 0));
    end component;
    
    signal input : STD_LOGIC_VECTOR (3 downto 0);
    signal output : STD_LOGIC_VECTOR (3 downto 0);
    
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
    
    Map_Complement : ComplementA1 PORT MAP(input, output);
end Behavioral;