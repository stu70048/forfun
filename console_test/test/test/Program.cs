using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace test
{
	class Program
	{
		static void Main(string[] args)
		{
			Console.WriteLine("Hello World!");
			Console.WriteLine("{0}", (uint)_BIT.BIT31);
			var a = new Program();
			byte[] data;
			a.BitsToByte(1, 0, 0, 1, 0, 1, 0, 1);
			Console.WriteLine("{0:X}", a.BitsToByte(1, 0, 0, 1, 0, 1, 0, 1));
			Console.WriteLine("{0:X}", a.BitsTo2Byte(1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0));
			Console.WriteLine("{0:d}", (int)(60 * 10e6 / 10 / 10e3 / 2 - 1));
			Console.WriteLine("{0:d}", (int)(10e3));
			a.Send_Data("ooooooooo");
			a.savebin();
			a.readbin(out data);
			Console.WriteLine("{0:x}", data);
			Console.WriteLine(Encoding.UTF8.GetString(data));
			//Console.WriteLine(Encoding.Default.GetString(data));
			Console.WriteLine(BitConverter.ToString(data));
			var c = new Person
			{
				Age = 20
			};
			c.doit();
			List<Auction> acutions = new List<Auction>();

			foreach (Auction aPart in acutions)
			{
				Console.WriteLine(aPart);
			}

            Console.WriteLine(c.Age.ToString());
			var b = new Person();
			Console.WriteLine(b.Age.ToString());
			b.Age = 10;
			Console.WriteLine(c.Age.ToString());
			Console.WriteLine(BitConverter.ToString(c.EDID).Replace("-", ",").ToLower());
			Console.WriteLine(c);
			c.EDID = new byte[] { 0x00 };
			Console.WriteLine(b);
			b.EDID = new byte[] { 0x01,0x12,0x22};
			Console.WriteLine(b);
			Console.WriteLine(c.ToString());
			//Console.WriteLine(c.EDID.ToString());
		}

		private byte Send_Data(string message)
		{

			//NumBytesToSend = BytesToSend;

			Console.WriteLine(DateTime.Now.ToString("HH:mm:ss") + "\t" + "[ERROR]" + message + " write command fail");
			return 0;
		}
		public enum _Table
		{
			TRUE = 1,
			FALSE = 0,
			SUCCESS = 1,
			FAIL = 0,
			ON = 1,
			OFF = 0,
			ENABLE = 1,
			DISABLE = 0,
			VALID = 1,
			INVALID = 0,
			NACK = 1,
			ACK = 0,
		}
		public enum _BIT : uint
		{
			BIT0 = 0x01U << 0,
			BIT1 = 0x01U << 1,
			BIT2 = 0x01U << 2,
			BIT3 = 0x01U << 3,
			BIT4 = 0x01U << 4,
			BIT5 = 0x01U << 5,
			BIT6 = 0x01U << 6,
			BIT7 = 0x01U << 7,
			BIT8 = 0x01U << 8,
			BIT9 = 0x01U << 9,
			BIT10 = 0x01U << 10,
			BIT11 = 0x01U << 11,
			BIT12 = 0x01U << 12,
			BIT13 = 0x01U << 13,
			BIT14 = 0x01U << 14,
			BIT15 = 0x01U << 15,
			BIT16 = 0x01U << 16,
			BIT17 = 0x01U << 17,
			BIT18 = 0x01U << 18,
			BIT19 = 0x01U << 19,
			BIT20 = 0x01U << 20,
			BIT21 = 0x01U << 21,
			BIT22 = 0x01U << 22,
			BIT23 = 0x01U << 23,
			BIT24 = 0x01U << 24,
			BIT25 = 0x01U << 25,
			BIT26 = 0x01U << 26,
			BIT27 = 0x01U << 27,
			BIT28 = 0x01U << 28,
			BIT29 = 0x01U << 29,
			BIT30 = 0x01U << 30,
			BIT31 = 0x01U << 31,
		}

		public byte BitsToByte(in byte b7, in byte b6, in byte b5, in byte b4, in byte b3, in byte b2, in byte b1, in byte b0)
			=> (byte)((b7 << 7) | (b6 << 6) | (b5 << 5) | (b4 << 4) | (b3 << 3) | (b2 << 2) | (b1 << 1) | b0);

		public UInt16 BitsTo2Byte(in byte b15, in byte b14, in byte b13, in byte b12, in byte b11, in byte b10, in byte b9, in byte b8, in byte b7, in byte b6, in byte b5, in byte b4, in byte b3, in byte b2, in byte b1, in byte b0)
			=> (UInt16)((b15 << 15) | (b14 << 14) | (b13 << 13) | (b12 << 12) | (b11 << 11) | (b10 << 10) | (b9 << 9) | (b8 << 8) | (b7 << 7) | (b6 << 6) | (b5 << 5) | (b4 << 4) | (b3 << 3) | (b2 << 2) | (b1 << 1) | b0);
		public bool savebin()
		{
			BinaryWriter bw;
			string s = "I am happy";
			try
			{
				bw = new BinaryWriter(new FileStream("mydata", FileMode.Create));
			}
			catch (IOException e)
			{
				Console.WriteLine(e.Message + " Cannot create file.");

				return false;
			}
			//writing into the file
			try
			{

				bw.Write(s);
			}
			catch (IOException e)
			{
				Console.WriteLine(e.Message + "Cannot write to file.");

				return false;
			}

			bw.Close();
			return true;
		}
		public bool readbin(out byte[] data)
		{
			data = new byte[] { 0 };
			BinaryReader br;
			try
			{
				br = new BinaryReader(new FileStream("mydata", FileMode.Open));
				//data = br.ReadBytes(0xFFF);
				data = ReadAllBytes(br);
			}
			catch (IOException e)
			{
				Console.WriteLine(e.Message + " Cannot create file.");

				return false;
			}
			//writing into the file

			br.Close();
			return true;
		}
		public byte[] ReadAllBytes1(BinaryReader stream)
		{
			using (var ms = new MemoryStream())
			{
				//stream.CopyTo(ms);
				return ms.ToArray();
			}
		}
		public static byte[] ReadAllBytes(BinaryReader reader)
		{
			const int bufferSize = 3;
			using (var ms = new MemoryStream())
			{
				byte[] buffer = new byte[bufferSize];
				int count;
				while ((count = reader.Read(buffer, 0, buffer.Length)) != 0)
					ms.Write(buffer, 0, count);
				return ms.ToArray();
			}

		}
	}
	public class Person
	{
		//public  int Age { get; set; } = 10;
		private static int _age = 100;
		private static byte[] _edid = { 0x11,0x12} ;
		//salary 成員則是透過公用唯讀屬性存取
		public int Age
		{
			get { return _age; }
			set { _age = value; }
		}
		public byte[] EDID
		{
			get { return _edid; }
			set { _edid = value; }
		}
		
		public override string ToString()
		{
			return BitConverter.ToString(EDID).Replace("-", ",").ToLower();
		}
		
		public void doit()
		{
			List<Auction> acutions = new List<Auction>();
			acutions.Add(new Auction() { auctionID = "crank arm", quantity = 1234 });
		}
	}

	public class Auction
	{
		public string auctionID { get; set; }
		public string itemName { get; set; }
		public string itemID { get; set; }
		public string bid { get; set; }
		public string buyout { get; set; }
		public int quantity { get; set; }

		public override string ToString()
		{
			return "ID: " + auctionID + "   Name: " + quantity;
		}
	}
}
