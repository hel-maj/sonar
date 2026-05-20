/* ===== 23e0f0eb0 telegram.handlers.fishing_handle:18 ===== */
/* ghidra_name=FUN_23e0f0eb0 entry=23e0f0eb0 size=277 */

code * FUN_23e0f0eb0(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong lVar5;
  code *pcVar6;
  longlong lVar7;
  undefined8 *local_30 [2];
  
  lVar5 = DAT_23eea9200;
  lVar4 = DAT_23eea91e8;
  plVar1 = (longlong *)*param_3;
  lVar7 = *(longlong *)(DAT_23eea9200 + 0x18);
  if (lVar7 == -1) {
    lVar7 = (**(code **)(PyUnicode_Type_exref + 0x78))(DAT_23eea9200);
  }
  lVar2 = *(longlong *)(lVar4 + 0x20);
  if (*(char *)(lVar2 + 10) == '\0') {
    FUN_23e9136e0(lVar4,lVar5,lVar7,local_30);
LAB_23e0f0f90:
    if (local_30[0] != (undefined8 *)0x0) {
LAB_23e0f0f28:
      plVar3 = (longlong *)*local_30[0];
      if (plVar1 == plVar3) goto LAB_23e0f0f5e;
      if (plVar3 != (longlong *)0x0) {
        *plVar1 = *plVar1 + 1;
        *local_30[0] = plVar1;
        *(longlong *)(lVar4 + 0x18) = DAT_23ec0fcf8;
        DAT_23ec0fcf8 = DAT_23ec0fcf8 + 1;
        *plVar3 = *plVar3 + -1;
        if (*plVar3 == 0) {
          (**(code **)(plVar3[1] + 0x30))();
        }
        goto LAB_23e0f0f5e;
      }
    }
  }
  else {
    lVar7 = FUN_23e8cbd60(lVar2,lVar5);
    if (lVar7 != -1) {
      if (*(char *)(lVar2 + 10) == '\x02') {
        local_30[0] = (undefined8 *)(*(longlong *)(lVar4 + 0x28) + lVar7 * 8);
        goto LAB_23e0f0f90;
      }
      local_30[0] = (undefined8 *)
                    (lVar2 + 0x28 + (1L << (*(byte *)(lVar2 + 9) & 0x3f)) + lVar7 * 0x10);
      goto LAB_23e0f0f28;
    }
  }
  PyDict_SetItem(lVar4,lVar5,plVar1);
LAB_23e0f0f5e:
  pcVar6 = _Py_NoneStruct_exref;
  *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  return pcVar6;
}
