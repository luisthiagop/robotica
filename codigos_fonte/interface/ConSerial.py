import sys
import glob
import serial
import Draw

class ConSerial():
    async def serial_ports():
        """ Lists serial port names

            :raises EnvironmentError:
                On unsupported or unknown platforms
            :returns:
                A list of the serial ports available on the system
        """
        if sys.platform.startswith('win'):
            ports = ['COM%s' % (i + 1) for i in range(256)]
        elif sys.platform.startswith('linux') or sys.platform.startswith('cygwin'):
            # this excludes your current terminal "/dev/tty"
            ports = glob.glob('/dev/tty[A-Za-z]*')
        elif sys.platform.startswith('darwin'):
            ports = glob.glob('/dev/tty.*')
        else:
            raise EnvironmentError('Unsupported platform')

        result = []
        for port in ports:
            try:
                s = serial.Serial(port)
                s.close()
                result.append(port)
            except (OSError, serial.SerialException):
                pass
        
        print ("selecione uma porta:")
        for i in range(10):
            print("{0} - {1}".format(i,results[i]))
        sel = (int) (input(":"))

        print("a porta selecionada foi: {0}".format(results[sel]))
        
        try:
            s = serial.Serial(results[sel],9600)
            open_uix()
            return
        except:
            print("erro ao estabelecer conexão com a porta selecionada")
            return

        

    def open_uix():
        codeinput = CodeInput(lexer=KivyLexer())
        Draw().run()
  

