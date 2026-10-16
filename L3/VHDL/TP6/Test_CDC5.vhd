library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_logic_arith.ALL;

entity Test_CDC5 is
end Test_CDC5;

architecture Behavioral of Test_CDC5 is
    component CDC5 is
        Port ( a : in STD_LOGIC_VECTOR (3 downto 0);
               b : in STD_LOGIC_VECTOR (3 downto 0);
               led : out STD_LOGIC_VECTOR (7 downto 0);
               an : out STD_LOGIC_VECTOR (3 downto 0);
               seg : out STD_LOGIC_VECTOR (7 downto 0));
    end component;
    
    signal a : STD_LOGIC_VECTOR (3 downto 0);
    signal b : STD_LOGIC_VECTOR (3 downto 0);
    signal led : STD_LOGIC_VECTOR (7 downto 0);
    signal an : STD_LOGIC_VECTOR (3 downto 0);
    signal seg : STD_LOGIC_VECTOR (7 downto 0);
    
    signal period : time := 1ns;
    signal mot : STD_LOGIC_VECTOR (7 downto 0) := "00000000";
begin
    process
        variable val : integer :=0;
    begin
        boucle: FOR val in 0 to 255 loop
            mot <= conv_std_logic_vector(val,8);
            a(0) <= mot(0); a(1) <= mot(1); a(2) <= mot(2); a(3) <= mot(3);
            b(0) <= mot(4); b(1) <= mot(5); b(2) <= mot(6); b(3) <= mot(7);
            wait for period;
        end loop;
        wait;     
    end process;
    
    Test : CDC5 PORT MAP(a, b, led, an, seg);
end Behavioral;