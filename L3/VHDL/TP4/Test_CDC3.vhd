library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Test_CDC3 is
end Test_CDC3;

architecture Behavioral of Test_CDC3 is
    component CDC3
        Port ( in_a : in STD_LOGIC;
               in_b : in STD_LOGIC;
               in_c : in STD_LOGIC;
               i : in STD_LOGIC;
               a : out STD_LOGIC;
               b : out STD_LOGIC;
               c : out STD_LOGIC;
               d : out STD_LOGIC;
               e : out STD_LOGIC;
               f : out STD_LOGIC;
               g : out STD_LOGIC;
               dp : out STD_LOGIC;
               led_a : out STD_LOGIC;
               led_b : out STD_LOGIC;
               led_c : out STD_LOGIC;
               led_i : out STD_LOGIC);
    end component;
    
    signal in_a: STD_LOGIC:='0';
    signal in_b: STD_LOGIC:='0';
    signal in_c: STD_LOGIC:='0';
    signal i: STD_LOGIC:='0';
    signal a: STD_LOGIC:='0';
    signal b: STD_LOGIC:='0';
    signal c: STD_LOGIC:='0';
    signal d: STD_LOGIC:='0';
    signal e: STD_LOGIC:='0';
    signal f: STD_LOGIC:='0';
    signal g: STD_LOGIC:='0';
    signal dp: STD_LOGIC:='0';
    signal led_a: STD_LOGIC:='0';
    signal led_b: STD_LOGIC:='0';
    signal led_c: STD_LOGIC:='0';
    signal led_i: STD_LOGIC:='0';
    
    constant period:time :=10 ns;
begin
    Generate_In: process
    begin
        in_a <= '0'; in_b <= '0'; in_c <= '0'; i <='0';
        wait for period;
        in_a <= '1'; in_b <= '0'; in_c <= '0'; i <= '0';
        wait for period;
        in_a <= '0'; in_b <= '1'; in_c <= '0'; i <= '0';
        wait for period;
        in_a <= '1'; in_b <= '1'; in_c <= '0'; i <= '0';
        wait for period;
        in_a <= '0'; in_b <= '0'; in_c <= '1'; i <= '0';
        wait for period;
        in_a <= '1'; in_b <= '0'; in_c <= '1'; i <= '0';
        wait for period;
        in_a <= '0'; in_b <= '1'; in_c <= '1'; i <= '0';
        wait for period;
        in_a <= '1'; in_b <= '1'; in_c <= '1'; i <= '0';
        wait for period;
        
        in_a <= '0'; in_b <= '0'; in_c <= '0'; i <= '1';
        wait for period;
        in_a <= '1'; in_b <= '0'; in_c <= '0'; i <= '1';
        wait for period;
        in_a <= '0'; in_b <= '1'; in_c <= '0'; i <= '1';
        wait for period;
        in_a <= '1'; in_b <= '1'; in_c <= '0'; i <= '1';
        wait for period;
        in_a <= '0'; in_b <= '0'; in_c <= '1'; i <= '1';
        wait for period;
        in_a <= '1'; in_b <= '0'; in_c <= '1'; i <= '1';
        wait for period;
        in_a <= '0'; in_b <= '1'; in_c <= '1'; i <= '1';
        wait for period;
        in_a <= '1'; in_b <= '1'; in_c <= '1'; i <= '1';
        wait for period;
        
        in_a <= '0'; in_b <= '0'; in_c <= '0'; i <= '1';
        wait;
    end process;

    Test : CDC3 PORT MAP(in_a, in_b, in_c, i, a, b, c, d, e, f, g, dp, led_a, led_b, led_c, led_i);
end Behavioral;