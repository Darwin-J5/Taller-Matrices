import java.util.Date;

public class Main {
    public static void main(String[] args) {
        // Crear un cliente
        Cliente cliente = new Cliente();
        cliente.nombre = "Juan Pérez";
        cliente.email = "juan.perez@example.com";
        
        // Crear productos
        Producto producto1 = new Producto();
        producto1.nombre = "Laptop";
        producto1.precio = 1000.00;
        producto1.impuesto = 100.00; // Por ejemplo, 10%

        Producto producto2 = new Producto();
        producto2.nombre = "Mouse";
        producto2.precio = 20.00;
        producto2.impuesto = 2.00; // Por ejemplo, 10%

        // Crear una factura
        Factura factura = new Factura();
        factura.numeroFactura = "FAC-001";
        factura.fechaEmision = new Date();

        // Agregar productos a la factura
        factura.agregarProducto(producto1, 1);
        factura.agregarProducto(producto2, 2);

        // Calcular total y aplicar un descuento
        factura.calcularTotal();
        factura.aplicarDescuento(50.00); // Aplicar un descuento de 50.00

        // Generar comprobante
        factura.generarComprobante();
        
        // Enviar comprobante por email
        factura.enviarComprobantePorEmail();

        // Mostrar información de la factura
        System.out.println("Factura generada con éxito:");
        System.out.println("Número: " + factura.numeroFactura);
        System.out.println("Fecha: " + factura.fechaEmision);
        // Aquí podrías imprimir más detalles sobre la factura y los productos
    }
}
