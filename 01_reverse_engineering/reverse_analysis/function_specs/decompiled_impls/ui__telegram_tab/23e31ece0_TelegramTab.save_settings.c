/* ===== 23e31ece0 ui.telegram_tab:206 ===== */
/* ghidra_name=FUN_23e31ece0 entry=23e31ece0 size=1884 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_23e31ece0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  code *pcVar8;
  int iVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  
  plVar10 = _DAT_23eeb4c90;
  plVar1 = (longlong *)*param_3;
  if (_DAT_23eeb4c90 == (longlong *)0x0) {
LAB_23e31ed1a:
    _DAT_23eeb4c90 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeb4c88,DAT_23eeb4cf0,0x10);
  }
  else {
    lVar2 = *_DAT_23eeb4c90;
    if (1 < lVar2) {
      *_DAT_23eeb4c90 = lVar2 + -1;
      goto LAB_23e31ed1a;
    }
    if (_DAT_23eeb4c90[2] != 0) {
      *_DAT_23eeb4c90 = lVar2 + -1;
      if (lVar2 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23e31ed1a;
    }
  }
  plVar4 = _DAT_23eeb4c90;
  lVar2 = *(longlong *)(param_1 + 0x38);
  plVar10 = _DAT_23eeb4c90 + 9;
  lVar3 = *(longlong *)(lVar2 + 8);
  _DAT_23eeb4c90[0xf] = lVar3;
  *(longlong **)(lVar2 + 8) = plVar10;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar4[0xe] != 0)))) {
    plVar10 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  *plVar4 = *plVar4 + 1;
  uVar6 = DAT_23eeb3988;
  *(undefined4 *)(plVar4 + 8) = 0;
  plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,uVar6);
  if (plVar10 == (longlong *)0x0) {
    uVar6 = *(undefined8 *)(param_1 + 0x60);
    uVar7 = *(undefined8 *)(param_1 + 0x68);
    plVar11 = (longlong *)0x0;
    plVar10 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uVar14 = 0xd0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar13 = DAT_23ed6a4f8;
    goto joined_r0x00023e31f0c4;
  }
  *(undefined4 *)(plVar4 + 5) = 0xd0;
  plVar11 = (longlong *)FUN_23e91bfe0(param_1,plVar10,_DAT_23eeb3bd8);
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if (plVar11 == (longlong *)0x0) {
    plVar10 = *(longlong **)(param_1 + 0x70);
    uVar6 = *(undefined8 *)(param_1 + 0x60);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar7 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar13 = DAT_23ed6a4f8;
    uVar14 = 0xd0;
    goto joined_r0x00023e31f0c4;
  }
  plVar10 = (longlong *)FUN_23e8bc2f0(plVar11,DAT_23ed6ce40);
  if (plVar10 != (longlong *)0x0) {
    *(undefined4 *)(plVar4 + 5) = 0xd1;
    plVar12 = (longlong *)FUN_23e9557e0(param_1,plVar10,_DAT_23eeb3c38);
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if (plVar12 != (longlong *)0x0) {
      iVar9 = FUN_23a35f020(plVar12);
      if (iVar9 == -1) {
        uVar6 = *(undefined8 *)(param_1 + 0x60);
        uVar7 = *(undefined8 *)(param_1 + 0x68);
        uVar14 = 0xd1;
        uVar15 = 0xd1;
        plVar10 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *plVar12 = *plVar12 + -1;
        lVar2 = *plVar12;
joined_r0x00023e31f3e6:
        plVar13 = DAT_23ed6a4f8;
        if (lVar2 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
          plVar13 = DAT_23ed6a4f8;
          uVar14 = uVar15;
        }
      }
      else {
        if (iVar9 != 1) goto LAB_23e31ee54;
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        plVar10 = (longlong *)FUN_23e8bc2f0(plVar11,DAT_23ed6ce40);
        if (plVar10 != (longlong *)0x0) {
          *(undefined4 *)(plVar4 + 5) = 0xd2;
          plVar13 = (longlong *)FUN_23e9557e0(param_1,plVar10,_DAT_23eeb3be8);
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          if (plVar13 != (longlong *)0x0) {
            plVar10 = (longlong *)FUN_23e8bc2f0(plVar13,_DAT_23eeb3c10);
            *plVar13 = *plVar13 + -1;
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            if (plVar10 != (longlong *)0x0) {
              *(undefined4 *)(plVar4 + 5) = 0xd2;
              plVar12 = (longlong *)FUN_23e91a870(param_1,plVar10);
              *plVar10 = *plVar10 + -1;
              if (*plVar10 == 0) {
                (**(code **)(plVar10[1] + 0x30))(plVar10);
              }
              if (plVar12 != (longlong *)0x0) {
                iVar9 = FUN_23a35f020(plVar12);
                if (iVar9 != -1) {
                  if (iVar9 != 1) {
LAB_23e31ee54:
                    lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                    plVar10 = *(longlong **)(lVar2 + 0x28);
                    plVar4 = (longlong *)plVar10[2];
                    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                         *(undefined8 *)(lVar2 + 0x30);
                    *(undefined4 *)(plVar10 + 8) = 0xffffffff;
                    if (plVar4 != (longlong *)0x0) {
                      plVar10[2] = 0;
                      *plVar4 = *plVar4 + -1;
                      if (*plVar4 == 0) {
                        (**(code **)(plVar4[1] + 0x30))();
                      }
                    }
                    *plVar10 = *plVar10 + -1;
                    if (*plVar10 == 0) {
                      (**(code **)(plVar10[1] + 0x30))(plVar10);
                    }
                    plVar10[0xf] = 0;
                    *plVar11 = *plVar11 + -1;
                    if (*plVar11 == 0) {
                      (**(code **)(plVar11[1] + 0x30))(plVar11);
                    }
                    *plVar1 = *plVar1 + -1;
                    if (*plVar1 != 0) {
                      return plVar12;
                    }
                    (**(code **)(plVar1[1] + 0x30))(plVar1);
                    return plVar12;
                  }
                  *plVar12 = *plVar12 + -1;
                  if (*plVar12 == 0) {
                    (**(code **)(plVar12[1] + 0x30))(plVar12);
                  }
                  plVar10 = (longlong *)FUN_23e8bc2f0(plVar11,DAT_23ed6ce40);
                  if (plVar10 != (longlong *)0x0) {
                    *(undefined4 *)(plVar4 + 5) = 0xd3;
                    plVar13 = (longlong *)FUN_23e9557e0(param_1,plVar10,_DAT_23eeb3bf0);
                    *plVar10 = *plVar10 + -1;
                    if (*plVar10 == 0) {
                      (**(code **)(plVar10[1] + 0x30))(plVar10);
                    }
                    if (plVar13 != (longlong *)0x0) {
                      plVar10 = (longlong *)FUN_23e8bc2f0(plVar13,_DAT_23eeb3c10);
                      *plVar13 = *plVar13 + -1;
                      if (*plVar13 == 0) {
                        (**(code **)(plVar13[1] + 0x30))(plVar13);
                      }
                      if (plVar10 != (longlong *)0x0) {
                        *(undefined4 *)(plVar4 + 5) = 0xd3;
                        plVar12 = (longlong *)FUN_23e91a870(param_1,plVar10);
                        *plVar10 = *plVar10 + -1;
                        if (*plVar10 == 0) {
                          (**(code **)(plVar10[1] + 0x30))(plVar10);
                        }
                        if (plVar12 != (longlong *)0x0) goto LAB_23e31ee54;
                      }
                    }
                  }
                  uVar6 = *(undefined8 *)(param_1 + 0x60);
                  uVar7 = *(undefined8 *)(param_1 + 0x68);
                  plVar10 = *(longlong **)(param_1 + 0x70);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  plVar13 = DAT_23ed6a4f8;
                  uVar14 = 0xd3;
                  goto joined_r0x00023e31f0c4;
                }
                uVar6 = *(undefined8 *)(param_1 + 0x60);
                uVar7 = *(undefined8 *)(param_1 + 0x68);
                uVar14 = 0xd2;
                uVar15 = 0xd2;
                plVar10 = *(longlong **)(param_1 + 0x70);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *plVar12 = *plVar12 + -1;
                lVar2 = *plVar12;
                goto joined_r0x00023e31f3e6;
              }
            }
          }
        }
        uVar6 = *(undefined8 *)(param_1 + 0x60);
        uVar7 = *(undefined8 *)(param_1 + 0x68);
        uVar14 = 0xd2;
        plVar10 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar13 = DAT_23ed6a4f8;
      }
      goto joined_r0x00023e31f0c4;
    }
  }
  plVar10 = *(longlong **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar14 = 0xd1;
  uVar6 = *(undefined8 *)(param_1 + 0x60);
  uVar7 = *(undefined8 *)(param_1 + 0x68);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar13 = DAT_23ed6a4f8;
joined_r0x00023e31f0c4:
  DAT_23ed6a4f8 = plVar13;
  if (plVar10 == (longlong *)0x0) {
    if (plVar13 == (longlong *)0x0) {
      plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar13;
      *plVar13 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar8 = _PyRuntime_exref;
    plVar13[2] = 0;
    plVar13[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    lVar2 = *(longlong *)(pcVar8 + 0x1f8);
    *(undefined4 *)((longlong)plVar13 + 0x24) = uVar14;
    lVar2 = *(longlong *)(lVar2 + 0x10);
    *(undefined4 *)(plVar13 + 4) = 0xffffffff;
    lVar2 = *(longlong *)(lVar2 + 0x2e8);
    lVar3 = plVar13[-1];
    puVar5 = *(undefined8 **)(lVar2 + 8);
    *puVar5 = plVar13 + -2;
    plVar13[-2] = lVar2;
    plVar13[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar2 + 8) = plVar13 + -2;
    plVar12 = plVar13;
  }
  else {
    plVar12 = plVar10;
    if ((longlong *)plVar10[3] != plVar4) {
      if (plVar13 == (longlong *)0x0) {
        plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar13;
        *plVar13 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar8 = _PyRuntime_exref;
      plVar13[3] = (longlong)plVar4;
      *plVar4 = *plVar4 + 1;
      lVar2 = *(longlong *)(pcVar8 + 0x1f8);
      *(undefined4 *)((longlong)plVar13 + 0x24) = uVar14;
      *(undefined4 *)(plVar13 + 4) = 0xffffffff;
      lVar2 = *(longlong *)(*(longlong *)(lVar2 + 0x10) + 0x2e8);
      lVar3 = plVar13[-1];
      puVar5 = *(undefined8 **)(lVar2 + 8);
      *puVar5 = plVar13 + -2;
      plVar13[-2] = lVar2;
      plVar13[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
      lVar3 = *plVar10;
      *(longlong **)(lVar2 + 8) = plVar13 + -2;
      plVar13[2] = (longlong)plVar10;
      plVar12 = plVar13;
      if (lVar3 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
    }
  }
  FUN_23e8bba40(plVar4,&DAT_23ec5b76c,plVar1,plVar11);
  if (_DAT_23eeb4c90 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    _DAT_23eeb4c90 = (longlong *)0x0;
  }
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar10 = *(longlong **)(lVar2 + 0x28);
  plVar4 = (longlong *)plVar10[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
  *(undefined4 *)(plVar10 + 8) = 0xffffffff;
  if (plVar4 != (longlong *)0x0) {
    plVar10[2] = 0;
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))();
    }
  }
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  plVar10[0xf] = 0;
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,uVar6,uVar7,plVar12);
  return (longlong *)0x0;
}
