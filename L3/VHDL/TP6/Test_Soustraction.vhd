library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_logic_arith.ALL;

entity Test_Soustraction is
end Test_Soustraction;

architecture Behavioral of Test_Soustraction is
    component Soustraction is
        Port ( a : in STD_LOGIC_VECTOR (3 downto 0);
               b : in STD_LOGIC_VECTOR (3 downto 0);
               output : out STD_LOGIC_VECTOR (3 downto 0));
    end component;


    constant period:time:=2 ns;
    signal a : std_logic_vector (3 downto 0) := "0000";
    signal b : std_logic_vector (3 downto 0) := "0000";
    signal output : std_logic_vector (3 downto 0) := "0000";

begin
    process
        variable val_1 : integer :=0;
        variable val_2 : integer :=0;
    begin
        boucle_a: FOR val_1 in 0 to 15 loop
            boucle_b: FOR val_2 in 0 to 15 loop
                b <= conv_std_logic_vector(val_2,4);
                wait for period;
            end loop;
            a <= conv_std_logic_vector(val_1,4);
        end loop;
        wait;     
    end process;
    
    Mapping : Soustraction PORT MAP(a, b, output);
end Behavioral;