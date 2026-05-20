/* ===== 23e31de70 ui.telegram_tab:191 ===== */
/* ghidra_name=FUN_23e31de70 entry=23e31de70 size=1838 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e31de70(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  code *pcVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  
  plVar9 = _DAT_23eeb4cb0;
  plVar1 = (longlong *)*param_3;
  if (_DAT_23eeb4cb0 == (longlong *)0x0) {
LAB_23e31deaa:
    _DAT_23eeb4cb0 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeb4ca8,DAT_23eeb4cf0,0x10);
  }
  else {
    lVar2 = *_DAT_23eeb4cb0;
    if (1 < lVar2) {
      *_DAT_23eeb4cb0 = lVar2 + -1;
      goto LAB_23e31deaa;
    }
    if (_DAT_23eeb4cb0[2] != 0) {
      *_DAT_23eeb4cb0 = lVar2 + -1;
      if (lVar2 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      goto LAB_23e31deaa;
    }
  }
  plVar4 = _DAT_23eeb4cb0;
  lVar2 = *(longlong *)(param_1 + 0x38);
  plVar9 = _DAT_23eeb4cb0 + 9;
  lVar3 = *(longlong *)(lVar2 + 8);
  _DAT_23eeb4cb0[0xf] = lVar3;
  *(longlong **)(lVar2 + 8) = plVar9;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar4[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  *plVar4 = *plVar4 + 1;
  uVar6 = DAT_23eeb3988;
  *(undefined4 *)(plVar4 + 8) = 0;
  plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,uVar6);
  if (plVar9 == (longlong *)0x0) {
    uVar6 = *(undefined8 *)(param_1 + 0x60);
    uVar7 = *(undefined8 *)(param_1 + 0x68);
    plVar10 = (longlong *)0x0;
    plVar9 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uVar14 = 0xc1;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar12 = DAT_23ed6a4f8;
    goto joined_r0x00023e31e3c4;
  }
  *(undefined4 *)(plVar4 + 5) = 0xc1;
  plVar10 = (longlong *)FUN_23e91bfe0(param_1,plVar9,_DAT_23eeb3bd8);
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if (plVar10 == (longlong *)0x0) {
    plVar9 = *(longlong **)(param_1 + 0x70);
    uVar6 = *(undefined8 *)(param_1 + 0x60);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar7 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar12 = DAT_23ed6a4f8;
    uVar14 = 0xc1;
    goto joined_r0x00023e31e3c4;
  }
  plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eeb3b10);
  if (plVar9 != (longlong *)0x0) {
    plVar11 = (longlong *)FUN_23e8bc2f0(plVar9,_DAT_23eeb3be0);
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    if (plVar11 != (longlong *)0x0) {
      plVar9 = (longlong *)FUN_23e8bc2f0(plVar10,DAT_23ed6ce40);
      if (plVar9 == (longlong *)0x0) {
LAB_23e31e4d0:
        uVar6 = *(undefined8 *)(param_1 + 0x60);
        uVar7 = *(undefined8 *)(param_1 + 0x68);
        uVar14 = 0xc2;
        uVar13 = 0xc2;
        plVar9 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *plVar11 = *plVar11 + -1;
        lVar2 = *plVar11;
      }
      else {
        *(undefined4 *)(plVar4 + 5) = 0xc2;
        plVar12 = (longlong *)FUN_23e9557e0(param_1,plVar9,_DAT_23eeb3be8);
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        if (plVar12 == (longlong *)0x0) goto LAB_23e31e4d0;
        *(undefined4 *)(plVar4 + 5) = 0xc2;
        plVar9 = (longlong *)FUN_23e914090(param_1,plVar11,plVar12);
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        if (plVar9 == (longlong *)0x0) goto LAB_23e31e3a0;
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eeb3b58);
        if (plVar9 == (longlong *)0x0) {
LAB_23e31e570:
          uVar6 = *(undefined8 *)(param_1 + 0x60);
          uVar7 = *(undefined8 *)(param_1 + 0x68);
          plVar9 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plVar12 = DAT_23ed6a4f8;
          uVar14 = 0xc3;
          goto joined_r0x00023e31e3c4;
        }
        plVar11 = (longlong *)FUN_23e8bc2f0(plVar9,_DAT_23eeb3be0);
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        if (plVar11 == (longlong *)0x0) goto LAB_23e31e570;
        plVar9 = (longlong *)FUN_23e8bc2f0(plVar10,DAT_23ed6ce40);
        if (plVar9 != (longlong *)0x0) {
          *(undefined4 *)(plVar4 + 5) = 0xc3;
          plVar12 = (longlong *)FUN_23e9557e0(param_1,plVar9,_DAT_23eeb3bf0);
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          if (plVar12 != (longlong *)0x0) {
            *(undefined4 *)(plVar4 + 5) = 0xc3;
            plVar9 = (longlong *)FUN_23e914090(param_1,plVar11,plVar12);
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            if (plVar9 != (longlong *)0x0) {
              *plVar9 = *plVar9 + -1;
              if (*plVar9 == 0) {
                (**(code **)(plVar9[1] + 0x30))(plVar9);
              }
              lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
              plVar9 = *(longlong **)(lVar2 + 0x28);
              plVar4 = (longlong *)plVar9[2];
              *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
              *(undefined4 *)(plVar9 + 8) = 0xffffffff;
              if (plVar4 != (longlong *)0x0) {
                plVar9[2] = 0;
                *plVar4 = *plVar4 + -1;
                if (*plVar4 == 0) {
                  (**(code **)(plVar4[1] + 0x30))();
                }
              }
              *plVar9 = *plVar9 + -1;
              if (*plVar9 == 0) {
                (**(code **)(plVar9[1] + 0x30))(plVar9);
              }
              plVar9[0xf] = 0;
              pcVar8 = _Py_NoneStruct_exref;
              *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
              *plVar10 = *plVar10 + -1;
              if (*plVar10 == 0) {
                (**(code **)(plVar10[1] + 0x30))(plVar10);
              }
              *plVar1 = *plVar1 + -1;
              if (*plVar1 != 0) {
                return pcVar8;
              }
              (**(code **)(plVar1[1] + 0x30))(plVar1);
              return pcVar8;
            }
            goto LAB_23e31e570;
          }
        }
        uVar6 = *(undefined8 *)(param_1 + 0x60);
        uVar7 = *(undefined8 *)(param_1 + 0x68);
        uVar14 = 0xc3;
        uVar13 = 0xc3;
        plVar9 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *plVar11 = *plVar11 + -1;
        lVar2 = *plVar11;
      }
      plVar12 = DAT_23ed6a4f8;
      if (lVar2 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
        plVar12 = DAT_23ed6a4f8;
        uVar14 = uVar13;
      }
      goto joined_r0x00023e31e3c4;
    }
  }
LAB_23e31e3a0:
  plVar9 = *(longlong **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar14 = 0xc2;
  uVar6 = *(undefined8 *)(param_1 + 0x60);
  uVar7 = *(undefined8 *)(param_1 + 0x68);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar12 = DAT_23ed6a4f8;
joined_r0x00023e31e3c4:
  DAT_23ed6a4f8 = plVar12;
  if (plVar9 == (longlong *)0x0) {
    if (plVar12 == (longlong *)0x0) {
      plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar12;
      *plVar12 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar11 = plVar12;
    }
    pcVar8 = _PyRuntime_exref;
    plVar11[2] = 0;
    plVar11[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    lVar2 = *(longlong *)(pcVar8 + 0x1f8);
    *(undefined4 *)((longlong)plVar11 + 0x24) = uVar14;
    lVar2 = *(longlong *)(lVar2 + 0x10);
    *(undefined4 *)(plVar11 + 4) = 0xffffffff;
    lVar2 = *(longlong *)(lVar2 + 0x2e8);
    lVar3 = plVar11[-1];
    puVar5 = *(undefined8 **)(lVar2 + 8);
    *puVar5 = plVar11 + -2;
    plVar11[-2] = lVar2;
    plVar11[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar2 + 8) = plVar11 + -2;
  }
  else {
    plVar11 = plVar9;
    if ((longlong *)plVar9[3] != plVar4) {
      if (plVar12 == (longlong *)0x0) {
        plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar12;
        *plVar12 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        plVar11 = plVar12;
      }
      pcVar8 = _PyRuntime_exref;
      plVar11[3] = (longlong)plVar4;
      *plVar4 = *plVar4 + 1;
      lVar2 = *(longlong *)(pcVar8 + 0x1f8);
      *(undefined4 *)((longlong)plVar11 + 0x24) = uVar14;
      *(undefined4 *)(plVar11 + 4) = 0xffffffff;
      lVar2 = *(longlong *)(*(longlong *)(lVar2 + 0x10) + 0x2e8);
      lVar3 = plVar11[-1];
      puVar5 = *(undefined8 **)(lVar2 + 8);
      *puVar5 = plVar11 + -2;
      plVar11[-2] = lVar2;
      plVar11[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
      lVar3 = *plVar9;
      *(longlong **)(lVar2 + 8) = plVar11 + -2;
      plVar11[2] = (longlong)plVar9;
      if (lVar3 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
    }
  }
  FUN_23e8bba40(plVar4,&DAT_23ec5b76c,plVar1,plVar10);
  if (_DAT_23eeb4cb0 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    _DAT_23eeb4cb0 = (longlong *)0x0;
  }
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar9 = *(longlong **)(lVar2 + 0x28);
  plVar4 = (longlong *)plVar9[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
  *(undefined4 *)(plVar9 + 8) = 0xffffffff;
  if (plVar4 != (longlong *)0x0) {
    plVar9[2] = 0;
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))();
    }
  }
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  plVar9[0xf] = 0;
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,uVar6,uVar7,plVar11);
  return (code *)0x0;
}
