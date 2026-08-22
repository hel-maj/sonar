# Historical item-info OCR evidence

Этот каталог хранит только nonshipping language-neutral screenshots и
результаты старого characterization прогона. Исполняемый legacy detector
удален; каталог не входит в build graph или release bundle.

Канонические test inputs находятся в
`tests/fixtures/inventory_item_info`. Новая production capability должна
потреблять их через C++ detector tests и не добавлять script/runtime adapter.
