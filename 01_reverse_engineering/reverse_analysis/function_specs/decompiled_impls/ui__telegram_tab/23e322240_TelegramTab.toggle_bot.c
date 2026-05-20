/* ===== 23e322240 ui.telegram_tab:264 ===== */
/* ghidra_name=FUN_23e322240 entry=23e322240 size=2117 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e322240(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  code *pcVar8;
  char cVar9;
  int iVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  undefined4 uVar14;
  
  plVar11 = _DAT_23eeb4c50;
  plVar1 = (longlong *)*param_3;
  if (_DAT_23eeb4c50 == (longlong *)0x0) {
LAB_23e32227a:
    _DAT_23eeb4c50 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeb4c48,DAT_23eeb4cf0,8);
  }
  else {
    lVar2 = *_DAT_23eeb4c50;
    if (1 < lVar2) {
      *_DAT_23eeb4c50 = lVar2 + -1;
      goto LAB_23e32227a;
    }
    if (_DAT_23eeb4c50[2] != 0) {
      *_DAT_23eeb4c50 = lVar2 + -1;
      if (lVar2 + -1 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      goto LAB_23e32227a;
    }
  }
  plVar4 = _DAT_23eeb4c50;
  lVar2 = *(longlong *)(param_1 + 0x38);
  plVar11 = _DAT_23eeb4c50 + 9;
  lVar3 = *(longlong *)(lVar2 + 8);
  _DAT_23eeb4c50[0xf] = lVar3;
  *(longlong **)(lVar2 + 8) = plVar11;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar4[0xe] != 0)))) {
    plVar11 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar11;
    if (plVar11 != (longlong *)0x0) {
      *plVar11 = *plVar11 + 1;
    }
  }
  *plVar4 = *plVar4 + 1;
  uVar6 = DAT_23eeb3990;
  *(undefined4 *)(plVar4 + 8) = 0;
  plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,uVar6);
  if (plVar11 == (longlong *)0x0) {
    uVar6 = *(undefined8 *)(param_1 + 0x60);
    uVar7 = *(undefined8 *)(param_1 + 0x68);
    uVar14 = 0x10a;
    plVar12 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar11 = DAT_23ed6a4f8;
    goto joined_r0x00023e322713;
  }
  iVar10 = FUN_23a35f020(plVar11);
  lVar2 = *plVar11 + -1;
  if (iVar10 == -1) {
    uVar6 = *(undefined8 *)(param_1 + 0x60);
    uVar7 = *(undefined8 *)(param_1 + 0x68);
    plVar12 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *plVar11 = lVar2;
    if (lVar2 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    uVar14 = 0x10a;
    plVar11 = DAT_23ed6a4f8;
    goto joined_r0x00023e322713;
  }
  *plVar11 = lVar2;
  if (lVar2 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if (iVar10 != 0) {
    plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eeb3990);
    if (plVar11 != (longlong *)0x0) {
      *(undefined4 *)(plVar4 + 5) = 0x10b;
      plVar12 = (longlong *)FUN_23e91bfe0(param_1,plVar11,_DAT_23eeb3ce8);
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      if (plVar12 != (longlong *)0x0) {
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        cVar9 = FUN_23e8d9ac0(plVar1,DAT_23eeb3990,_Py_NoneStruct_exref);
        if (cVar9 == '\0') {
          uVar6 = *(undefined8 *)(param_1 + 0x60);
          uVar7 = *(undefined8 *)(param_1 + 0x68);
          uVar14 = 0x10c;
          plVar12 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plVar11 = DAT_23ed6a4f8;
          goto joined_r0x00023e322713;
        }
        goto LAB_23e32234b;
      }
    }
    uVar6 = *(undefined8 *)(param_1 + 0x60);
    uVar7 = *(undefined8 *)(param_1 + 0x68);
    uVar14 = 0x10b;
    plVar12 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar11 = DAT_23ed6a4f8;
    goto joined_r0x00023e322713;
  }
LAB_23e32234b:
  plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eeb3b78);
  lVar2 = _DAT_23eeb3b70;
  if (plVar11 != (longlong *)0x0) {
    *(undefined4 *)(plVar4 + 5) = 0x10e;
    plVar12 = (longlong *)
              FUN_23e915840(param_1,plVar11,_DAT_23eeb3be0,*(undefined8 *)(lVar2 + 0x18));
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    if (plVar12 != (longlong *)0x0) {
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eeb3b78);
      lVar2 = _DAT_23eeb3b80;
      if (plVar11 != (longlong *)0x0) {
        *(undefined4 *)(plVar4 + 5) = 0x10f;
        plVar12 = (longlong *)
                  FUN_23e915840(param_1,plVar11,_DAT_23eeb3a40,*(undefined8 *)(lVar2 + 0x18));
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        if (plVar12 != (longlong *)0x0) {
          *plVar12 = *plVar12 + -1;
          if (*plVar12 == 0) {
            (**(code **)(plVar12[1] + 0x30))(plVar12);
          }
          plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eeb3b78);
          if (plVar11 != (longlong *)0x0) {
            plVar13 = (longlong *)FUN_23e8bc2f0(plVar11,_DAT_23eeb3cc8);
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            if (plVar13 != (longlong *)0x0) {
              plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eeb3b78);
              if (plVar11 != (longlong *)0x0) {
                *(undefined4 *)(plVar4 + 5) = 0x110;
                plVar12 = (longlong *)FUN_23e91bfe0(param_1,plVar11,_DAT_23eeb3cd0);
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                }
                if (plVar12 != (longlong *)0x0) {
                  *(undefined4 *)(plVar4 + 5) = 0x110;
                  plVar11 = (longlong *)FUN_23e914090(param_1,plVar13,plVar12);
                  *plVar13 = *plVar13 + -1;
                  if (*plVar13 == 0) {
                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                  }
                  *plVar12 = *plVar12 + -1;
                  if (*plVar12 == 0) {
                    (**(code **)(plVar12[1] + 0x30))(plVar12);
                  }
                  if (plVar11 != (longlong *)0x0) {
                    *plVar11 = *plVar11 + -1;
                    if (*plVar11 == 0) {
                      (**(code **)(plVar11[1] + 0x30))(plVar11);
                    }
                    lVar2 = _DAT_23eeb3cf0;
                    *(undefined4 *)(plVar4 + 5) = 0x111;
                    plVar11 = (longlong *)
                              FUN_23e915840(param_1,plVar1,_DAT_23eeb3c60,
                                            *(undefined8 *)(lVar2 + 0x18));
                    if (plVar11 != (longlong *)0x0) {
                      *plVar11 = *plVar11 + -1;
                      if (*plVar11 == 0) {
                        (**(code **)(plVar11[1] + 0x30))(plVar11);
                      }
                      lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                      plVar11 = *(longlong **)(lVar2 + 0x28);
                      plVar4 = (longlong *)plVar11[2];
                      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                           *(undefined8 *)(lVar2 + 0x30);
                      *(undefined4 *)(plVar11 + 8) = 0xffffffff;
                      if (plVar4 != (longlong *)0x0) {
                        plVar11[2] = 0;
                        *plVar4 = *plVar4 + -1;
                        if (*plVar4 == 0) {
                          (**(code **)(plVar4[1] + 0x30))();
                        }
                      }
                      *plVar11 = *plVar11 + -1;
                      if (*plVar11 == 0) {
                        (**(code **)(plVar11[1] + 0x30))(plVar11);
                      }
                      plVar11[0xf] = 0;
                      pcVar8 = _Py_NoneStruct_exref;
                      *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
                      *plVar1 = *plVar1 + -1;
                      if (*plVar1 != 0) {
                        return pcVar8;
                      }
                      (**(code **)(plVar1[1] + 0x30))(plVar1);
                      return pcVar8;
                    }
                    uVar6 = *(undefined8 *)(param_1 + 0x60);
                    uVar7 = *(undefined8 *)(param_1 + 0x68);
                    uVar14 = 0x111;
                    plVar12 = *(longlong **)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    plVar11 = DAT_23ed6a4f8;
                    goto joined_r0x00023e322713;
                  }
                  goto LAB_23e322860;
                }
              }
              uVar6 = *(undefined8 *)(param_1 + 0x60);
              uVar7 = *(undefined8 *)(param_1 + 0x68);
              uVar14 = 0x110;
              plVar12 = *(longlong **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *plVar13 = *plVar13 + -1;
              plVar11 = DAT_23ed6a4f8;
              if (*plVar13 == 0) {
                (**(code **)(plVar13[1] + 0x30))(plVar13);
                uVar14 = 0x110;
                plVar11 = DAT_23ed6a4f8;
              }
              goto joined_r0x00023e322713;
            }
          }
LAB_23e322860:
          plVar12 = *(longlong **)(param_1 + 0x70);
          uVar6 = *(undefined8 *)(param_1 + 0x60);
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar7 = *(undefined8 *)(param_1 + 0x68);
          uVar14 = 0x110;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar11 = DAT_23ed6a4f8;
          goto joined_r0x00023e322713;
        }
      }
      plVar12 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar14 = 0x10f;
      uVar6 = *(undefined8 *)(param_1 + 0x60);
      uVar7 = *(undefined8 *)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar11 = DAT_23ed6a4f8;
      goto joined_r0x00023e322713;
    }
  }
  uVar6 = *(undefined8 *)(param_1 + 0x60);
  uVar7 = *(undefined8 *)(param_1 + 0x68);
  uVar14 = 0x10e;
  plVar12 = *(longlong **)(param_1 + 0x70);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  *(undefined8 *)(param_1 + 0x70) = 0;
  plVar11 = DAT_23ed6a4f8;
joined_r0x00023e322713:
  DAT_23ed6a4f8 = plVar11;
  if (plVar12 == (longlong *)0x0) {
    if (plVar11 == (longlong *)0x0) {
      plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar11;
      *plVar11 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar8 = _PyRuntime_exref;
    plVar11[3] = (longlong)plVar4;
    plVar11[2] = 0;
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
    *(longlong **)(lVar2 + 8) = plVar11 + -2;
    plVar13 = plVar11;
  }
  else {
    plVar13 = plVar12;
    if ((longlong *)plVar12[3] != plVar4) {
      if (plVar11 == (longlong *)0x0) {
        plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar11;
        *plVar11 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
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
      lVar3 = *plVar12;
      *(longlong **)(lVar2 + 8) = plVar11 + -2;
      plVar11[2] = (longlong)plVar12;
      plVar13 = plVar11;
      if (lVar3 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
    }
  }
  FUN_23e8bba40(plVar4,&DAT_23ec5b76f,plVar1);
  if (_DAT_23eeb4c50 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    _DAT_23eeb4c50 = (longlong *)0x0;
  }
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar11 = *(longlong **)(lVar2 + 0x28);
  plVar4 = (longlong *)plVar11[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
  *(undefined4 *)(plVar11 + 8) = 0xffffffff;
  if (plVar4 != (longlong *)0x0) {
    plVar11[2] = 0;
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))();
    }
  }
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  plVar11[0xf] = 0;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,uVar6,uVar7,plVar13);
  return (code *)0x0;
}
