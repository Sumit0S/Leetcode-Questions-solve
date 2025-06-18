select product.product_name ,Sales.year,Sales.price
from Sales
left join Product
on sales.product_id=product.product_id