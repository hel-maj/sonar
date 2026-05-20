/* ===== 23e31e5e0 ui.telegram_tab:197 ===== */
/* ghidra_name=FUN_23e31e5e0 entry=23e31e5e0 size=1736 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong FUN_23e31e5e0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  code *pcVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong lVar11;
  longlong *plVar12;
  undefined4 uVar13;
  
  plVar8 = _DAT_23eeb4ca0;
  plVar1 = (longlong *)*param_3;
  if (_DAT_23eeb4ca0 == (longlong *)0x0) {
LAB_23e31e61a:
    _DAT_23eeb4ca0 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeb4c98,DAT_23eeb4cf0,0x10);
  }
  else {
    lVar11 = *_DAT_23eeb4ca0;
    if (1 < lVar11) {
      *_DAT_23eeb4ca0 = lVar11 + -1;
      goto LAB_23e31e61a;
    }
    if (_DAT_23eeb4ca0[2] != 0) {
      *_DAT_23eeb4ca0 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23e31e61a;
    }
  }
  plVar3 = _DAT_23eeb4ca0;
  lVar11 = *(longlong *)(param_1 + 0x38);
  plVar8 = _DAT_23eeb4ca0 + 9;
  lVar2 = *(longlong *)(lVar11 + 8);
  _DAT_23eeb4ca0[0xf] = lVar2;
  *(longlong **)(lVar11 + 8) = plVar8;
  if ((lVar2 != 0) &&
     (((*(char *)(lVar2 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar2 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar2 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar2 + 0x38))
       ) && (plVar3[0xe] != 0)))) {
    plVar8 = *(longlong **)(lVar2 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar8;
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  uVar5 = _DAT_23eeb3b10;
  *(undefined4 *)(plVar3 + 8) = 0;
  uVar6 = _DAT_23eeb3c00;
  plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,uVar5);
  if (plVar8 == (longlong *)0x0) {
LAB_23e31eac4:
    plVar9 = (longlong *)0x0;
    plVar8 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar13 = 200;
    uVar5 = *(undefined8 *)(param_1 + 0x60);
    uVar6 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar10 = DAT_23ed6a4f8;
  }
  else {
    *(undefined4 *)(plVar3 + 5) = 200;
    plVar9 = (longlong *)FUN_23e91bfe0(param_1,plVar8,_DAT_23eeb3c08);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    if (plVar9 != (longlong *)0x0) {
      plVar8 = (longlong *)FUN_23e8bc2f0(plVar9,_DAT_23eeb3c10);
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      if (plVar8 == (longlong *)0x0) goto LAB_23e31eac4;
      *(undefined4 *)(plVar3 + 5) = 200;
      plVar10 = (longlong *)FUN_23e91a870(param_1,plVar8);
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      if (plVar10 != (longlong *)0x0) {
        plVar9 = (longlong *)_PyDict_NewPresized(3);
        PyDict_SetItem(plVar9,uVar6,plVar10);
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        uVar5 = _DAT_23eeb3c18;
        plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eeb3b58);
        if (plVar8 != (longlong *)0x0) {
          *(undefined4 *)(plVar3 + 5) = 0xc9;
          plVar10 = (longlong *)FUN_23e91bfe0(param_1,plVar8,_DAT_23eeb3c08);
          *plVar8 = *plVar8 + -1;
          if (*plVar8 == 0) {
            (**(code **)(plVar8[1] + 0x30))(plVar8);
          }
          if (plVar10 != (longlong *)0x0) {
            plVar8 = (longlong *)FUN_23e8bc2f0(plVar10,_DAT_23eeb3c10);
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            if (plVar8 != (longlong *)0x0) {
              *(undefined4 *)(plVar3 + 5) = 0xc9;
              plVar10 = (longlong *)FUN_23e91a870(param_1,plVar8);
              *plVar8 = *plVar8 + -1;
              if (*plVar8 == 0) {
                (**(code **)(plVar8[1] + 0x30))(plVar8);
              }
              if (plVar10 != (longlong *)0x0) {
                PyDict_SetItem(plVar9,uVar5,plVar10);
                *plVar10 = *plVar10 + -1;
                if (*plVar10 == 0) {
                  (**(code **)(plVar10[1] + 0x30))(plVar10);
                }
                PyDict_SetItem(plVar9,_DAT_23eeb3c20,_Py_TrueStruct_exref);
                plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eeb3988);
                if (plVar8 != (longlong *)0x0) {
                  *(undefined4 *)(plVar3 + 5) = 0xcc;
                  lVar11 = FUN_23e915840(param_1,plVar8,_DAT_23eeb3c28,plVar9);
                  *plVar8 = *plVar8 + -1;
                  if (*plVar8 == 0) {
                    (**(code **)(plVar8[1] + 0x30))(plVar8);
                  }
                  if (lVar11 != 0) {
                    lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                    plVar8 = *(longlong **)(lVar2 + 0x28);
                    plVar3 = (longlong *)plVar8[2];
                    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                         *(undefined8 *)(lVar2 + 0x30);
                    *(undefined4 *)(plVar8 + 8) = 0xffffffff;
                    if (plVar3 != (longlong *)0x0) {
                      plVar8[2] = 0;
                      *plVar3 = *plVar3 + -1;
                      if (*plVar3 == 0) {
                        (**(code **)(plVar3[1] + 0x30))();
                      }
                    }
                    *plVar8 = *plVar8 + -1;
                    if (*plVar8 == 0) {
                      (**(code **)(plVar8[1] + 0x30))(plVar8);
                    }
                    plVar8[0xf] = 0;
                    *plVar9 = *plVar9 + -1;
                    if (*plVar9 == 0) {
                      (**(code **)(plVar9[1] + 0x30))(plVar9);
                    }
                    *plVar1 = *plVar1 + -1;
                    if (*plVar1 == 0) {
                      (**(code **)(plVar1[1] + 0x30))(plVar1);
                      return lVar11;
                    }
                    return lVar11;
                  }
                }
                uVar5 = *(undefined8 *)(param_1 + 0x60);
                uVar6 = *(undefined8 *)(param_1 + 0x68);
                uVar13 = 0xcc;
                plVar8 = *(longlong **)(param_1 + 0x70);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                plVar10 = DAT_23ed6a4f8;
                goto joined_r0x00023e31e951;
              }
            }
          }
        }
        uVar5 = *(undefined8 *)(param_1 + 0x60);
        uVar6 = *(undefined8 *)(param_1 + 0x68);
        plVar8 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        uVar13 = 0xc9;
        plVar9 = (longlong *)0x0;
        plVar10 = DAT_23ed6a4f8;
        goto joined_r0x00023e31e951;
      }
    }
    plVar8 = *(longlong **)(param_1 + 0x70);
    uVar5 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = (longlong *)0x0;
    uVar6 = *(undefined8 *)(param_1 + 0x68);
    uVar13 = 200;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar10 = DAT_23ed6a4f8;
  }
joined_r0x00023e31e951:
  DAT_23ed6a4f8 = plVar10;
  if (plVar8 == (longlong *)0x0) {
    if (plVar10 == (longlong *)0x0) {
      plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar10;
      *plVar10 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar12 = plVar10;
    }
    pcVar7 = _PyRuntime_exref;
    plVar12[3] = (longlong)plVar3;
    plVar12[2] = 0;
    *plVar3 = *plVar3 + 1;
    lVar11 = *(longlong *)(pcVar7 + 0x1f8);
    *(undefined4 *)((longlong)plVar12 + 0x24) = uVar13;
    *(undefined4 *)(plVar12 + 4) = 0xffffffff;
    lVar11 = *(longlong *)(*(longlong *)(lVar11 + 0x10) + 0x2e8);
    lVar2 = plVar12[-1];
    puVar4 = *(undefined8 **)(lVar11 + 8);
    *puVar4 = plVar12 + -2;
    plVar12[-2] = lVar11;
    plVar12[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar11 + 8) = plVar12 + -2;
  }
  else {
    plVar12 = plVar8;
    if ((longlong *)plVar8[3] != plVar3) {
      if (plVar10 == (longlong *)0x0) {
        plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar10;
        *plVar10 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        plVar12 = plVar10;
      }
      pcVar7 = _PyRuntime_exref;
      plVar12[3] = (longlong)plVar3;
      *plVar3 = *plVar3 + 1;
      lVar11 = *(longlong *)(pcVar7 + 0x1f8);
      *(undefined4 *)((longlong)plVar12 + 0x24) = uVar13;
      *(undefined4 *)(plVar12 + 4) = 0xffffffff;
      lVar11 = *(longlong *)(*(longlong *)(lVar11 + 0x10) + 0x2e8);
      lVar2 = plVar12[-1];
      puVar4 = *(undefined8 **)(lVar11 + 8);
      *puVar4 = plVar12 + -2;
      plVar12[-2] = lVar11;
      plVar12[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
      lVar2 = *plVar8;
      *(longlong **)(lVar11 + 8) = plVar12 + -2;
      plVar12[2] = (longlong)plVar8;
      if (lVar2 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
    }
  }
  FUN_23e8bba40(plVar3,&DAT_23ec5b76c,plVar1,plVar9);
  if (_DAT_23eeb4ca0 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23eeb4ca0 = (longlong *)0x0;
  }
  lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar8 = *(longlong **)(lVar11 + 0x28);
  plVar3 = (longlong *)plVar8[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
  *(undefined4 *)(plVar8 + 8) = 0xffffffff;
  if (plVar3 != (longlong *)0x0) {
    plVar8[2] = 0;
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))();
    }
  }
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  plVar8[0xf] = 0;
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,uVar5,uVar6,plVar12);
  return 0;
}
