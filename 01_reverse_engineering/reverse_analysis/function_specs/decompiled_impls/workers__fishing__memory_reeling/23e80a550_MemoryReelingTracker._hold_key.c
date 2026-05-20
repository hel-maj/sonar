/* ===== 23e80a550 workers.fishing.memory_reeling:MemoryReelingTracker._hold_key ===== */
/* ghidra_name=FUN_23e80a550 entry=23e80a550 size=1433 */

code * FUN_23e80a550(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined8 *puVar6;
  char cVar7;
  int iVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  undefined4 uVar12;
  code *pcVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  
  plVar9 = DAT_23eede900;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  if (DAT_23eede900 == (longlong *)0x0) {
LAB_23e80a58e:
    DAT_23eede900 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eede9b0,DAT_23eedd0f8,0x10);
  }
  else {
    lVar3 = *DAT_23eede900;
    if (1 < lVar3) {
      *DAT_23eede900 = lVar3 + -1;
      goto LAB_23e80a58e;
    }
    if (DAT_23eede900[2] != 0) {
      *DAT_23eede900 = lVar3 + -1;
      if (lVar3 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      goto LAB_23e80a58e;
    }
  }
  plVar5 = DAT_23eede900;
  lVar3 = *(longlong *)(param_1 + 0x38);
  plVar9 = DAT_23eede900 + 9;
  lVar4 = *(longlong *)(lVar3 + 8);
  DAT_23eede900[0xf] = lVar4;
  *(longlong **)(lVar3 + 8) = plVar9;
  if ((lVar4 != 0) &&
     (((*(char *)(lVar4 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar4 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar4 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar4 + 0x38))
       ) && (plVar5[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar4 + 0x28);
    *(longlong **)(plVar5[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  *plVar5 = *plVar5 + 1;
  uVar14 = DAT_23eedd1b0;
  *(undefined4 *)(plVar5 + 8) = 0;
  plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,uVar14);
  if (plVar9 != (longlong *)0x0) {
    iVar8 = FUN_23e912620(plVar9,plVar2);
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    pcVar13 = _Py_NoneStruct_exref;
    if (iVar8 != -1) {
      if (iVar8 == 1) {
        lVar3 = *(longlong *)(param_1 + 0x38);
        lVar4 = *(longlong *)(lVar3 + 8);
        *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
        plVar9 = *(longlong **)(lVar4 + 0x28);
        plVar5 = (longlong *)plVar9[2];
        *(undefined8 *)(lVar3 + 8) = *(undefined8 *)(lVar4 + 0x30);
        *(undefined4 *)(plVar9 + 8) = 0xffffffff;
        if (plVar5 != (longlong *)0x0) {
          plVar9[2] = 0;
          *plVar5 = *plVar5 + -1;
          if (*plVar5 == 0) {
            (**(code **)(plVar5[1] + 0x30))();
          }
        }
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        plVar9[0xf] = 0;
LAB_23e80a806:
        *plVar1 = *plVar1 + -1;
        if (*plVar1 == 0) {
          (**(code **)(plVar1[1] + 0x30))(plVar1);
        }
        *plVar2 = *plVar2 + -1;
        if (*plVar2 != 0) {
          return pcVar13;
        }
        (**(code **)(plVar2[1] + 0x30))(plVar2);
        return pcVar13;
      }
      *(undefined4 *)(plVar5 + 5) = 0xee;
      plVar9 = (longlong *)FUN_23e91bfe0(param_1,plVar1,DAT_23eedd258);
      if (plVar9 == (longlong *)0x0) {
        uVar14 = *(undefined8 *)(param_1 + 0x60);
        uVar15 = *(undefined8 *)(param_1 + 0x68);
        uVar12 = 0xee;
        plVar9 = *(longlong **)(param_1 + 0x70);
      }
      else {
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eedd120);
        if (plVar9 != (longlong *)0x0) {
          *(undefined4 *)(plVar5 + 5) = 0xef;
          plVar10 = (longlong *)FUN_23e915840(param_1,plVar9,DAT_23eedd300,plVar2);
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          if (plVar10 != (longlong *)0x0) {
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            cVar7 = FUN_23e8d9ac0(plVar1,DAT_23eedd1b0,plVar2);
            if (cVar7 != '\0') {
              lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
              plVar9 = *(longlong **)(lVar3 + 0x28);
              plVar5 = (longlong *)plVar9[2];
              *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar3 + 0x30);
              *(undefined4 *)(plVar9 + 8) = 0xffffffff;
              if (plVar5 != (longlong *)0x0) {
                plVar9[2] = 0;
                *plVar5 = *plVar5 + -1;
                if (*plVar5 == 0) {
                  (**(code **)(plVar5[1] + 0x30))();
                }
              }
              *plVar9 = *plVar9 + -1;
              if (*plVar9 == 0) {
                (**(code **)(plVar9[1] + 0x30))(plVar9);
              }
              plVar9[0xf] = 0;
              pcVar13 = _Py_NoneStruct_exref;
              *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
              goto LAB_23e80a806;
            }
            uVar14 = *(undefined8 *)(param_1 + 0x60);
            uVar15 = *(undefined8 *)(param_1 + 0x68);
            uVar12 = 0xf0;
            plVar9 = *(longlong **)(param_1 + 0x70);
            goto LAB_23e80a851;
          }
        }
        uVar14 = *(undefined8 *)(param_1 + 0x60);
        uVar15 = *(undefined8 *)(param_1 + 0x68);
        uVar12 = 0xef;
        plVar9 = *(longlong **)(param_1 + 0x70);
      }
      goto LAB_23e80a851;
    }
  }
  uVar14 = *(undefined8 *)(param_1 + 0x60);
  uVar15 = *(undefined8 *)(param_1 + 0x68);
  uVar12 = 0xec;
  plVar9 = *(longlong **)(param_1 + 0x70);
LAB_23e80a851:
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar10 = DAT_23ed6a4f8;
  if (plVar9 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar9 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar9;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar11 = plVar10;
    }
    pcVar13 = _PyRuntime_exref;
    plVar11[2] = 0;
    plVar11[3] = (longlong)plVar5;
    *plVar5 = *plVar5 + 1;
    lVar3 = *(longlong *)(pcVar13 + 0x1f8);
    *(undefined4 *)((longlong)plVar11 + 0x24) = uVar12;
    lVar3 = *(longlong *)(lVar3 + 0x10);
    *(undefined4 *)(plVar11 + 4) = 0xffffffff;
    lVar3 = *(longlong *)(lVar3 + 0x2e8);
    lVar4 = plVar11[-1];
    puVar6 = *(undefined8 **)(lVar3 + 8);
    *puVar6 = plVar11 + -2;
    plVar11[-2] = lVar3;
    plVar11[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar6;
    *(longlong **)(lVar3 + 8) = plVar11 + -2;
  }
  else {
    plVar11 = plVar9;
    if ((longlong *)plVar9[3] != plVar5) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar11 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar11;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        plVar11 = plVar10;
      }
      pcVar13 = _PyRuntime_exref;
      plVar11[3] = (longlong)plVar5;
      *plVar5 = *plVar5 + 1;
      lVar3 = *(longlong *)(pcVar13 + 0x1f8);
      *(undefined4 *)((longlong)plVar11 + 0x24) = uVar12;
      *(undefined4 *)(plVar11 + 4) = 0xffffffff;
      lVar3 = *(longlong *)(*(longlong *)(lVar3 + 0x10) + 0x2e8);
      lVar4 = plVar11[-1];
      puVar6 = *(undefined8 **)(lVar3 + 8);
      *puVar6 = plVar11 + -2;
      plVar11[-2] = lVar3;
      plVar11[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar6;
      lVar4 = *plVar9;
      *(longlong **)(lVar3 + 8) = plVar11 + -2;
      plVar11[2] = (longlong)plVar9;
      if (lVar4 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
    }
  }
  FUN_23e8bba40(plVar5,&DAT_23ec5e407,plVar1,plVar2);
  if (DAT_23eede900 == plVar5) {
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))(plVar5);
    }
    DAT_23eede900 = (longlong *)0x0;
  }
  lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar9 = *(longlong **)(lVar3 + 0x28);
  plVar5 = (longlong *)plVar9[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar3 + 0x30);
  *(undefined4 *)(plVar9 + 8) = 0xffffffff;
  if (plVar5 != (longlong *)0x0) {
    plVar9[2] = 0;
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))();
    }
  }
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  plVar9[0xf] = 0;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,uVar14,uVar15,plVar11);
  return (code *)0x0;
}
