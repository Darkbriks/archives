library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_logic_arith.ALL;

entity Test_Concatenation is
end Test_Concatenation;

architecture Behavioral of Test_Concatenation is
    component Concatenation is
        Port ( a : in STD_LOGIC_VECTOR (3 downto 0);
               b : in STD_LOGIC_VECTOR (3 downto 0);
               led : out STD_LOGIC_VECTOR (7 downto 0));
    end component;
    
    constant period:time:=10 ns;
    signal a : std_logic_vector (3 downto 0) := "0000";
    signal b : std_logic_vector (3 downto 0) := "0000";
    signal led : std_logic_vector (7 downto 0) := "00000000";

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
    
    Mapping : Concatenation PORT MAP(a, b, led);
end Behavioral;
