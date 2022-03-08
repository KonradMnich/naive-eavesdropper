template <int BUFFER_SIZE>
class NaiveEavesdropper
{
  private:
    int m_data[BUFFER_SIZE];
    byte m_result_id;
    byte m_input_pin;
     
  public:
    NaiveEavesdropper(byte input_pin=2)
    : m_input_pin{input_pin}, m_result_id{0}{};
  
    void initialize(int serial_baud=9600)
    {
      pinMode(m_input_pin, INPUT);
      Serial.begin(serial_baud);
      Serial.println("Ready to eavesdrop");
    }

    void eavesdrop()
    {
      int duration{0};
      bool old_state{LOW};
      bool new_state{HIGH};
      
      while (old_state == LOW)
      {
        old_state = digitalRead(m_input_pin);
      }
      
      for(auto && array_element : m_data)
      {
        while (old_state == new_state)
        {
          ++duration;
          new_state = digitalRead(m_input_pin);
        }
        old_state = new_state;
        array_element = duration;
        duration = 0;
      }
    }

    void print_gossip()
    {
      for(auto &i : m_data)
      {
        Serial.print(i);
        Serial.print(',');
      }
      Serial.println();
      ++m_result_id;
    }
};
