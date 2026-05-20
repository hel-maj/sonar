/* ===== 23e871880 workers.fishing.meal_system:285 ===== */
/* ghidra_name=FUN_23e871880 entry=23e871880 size=2342 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_23e871880(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined8 *puVar6;
  code *pcVar7;
  char cVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  undefined4 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  longlong *local_a8;
  undefined8 local_98;
  undefined8 uStack_90;
  longlong *local_88;
  longlong *local_78;
  longlong *plStack_70;
  longlong *local_68;
  
  plVar9 = _DAT_23eedec88;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  local_88 = (longlong *)0x0;
  local_98 = 0;
  uStack_90 = 0;
  if (_DAT_23eedec88 == (longlong *)0x0) {
LAB_23e8718db:
    _DAT_23eedec88 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedec80,DAT_23eed7940,0x28);
  }
  else {
    lVar3 = *_DAT_23eedec88;
    if (1 < lVar3) {
      *_DAT_23eedec88 = lVar3 + -1;
      goto LAB_23e8718db;
    }
    if (_DAT_23eedec88[2] != 0) {
      *_DAT_23eedec88 = lVar3 + -1;
      if (lVar3 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      goto LAB_23e8718db;
    }
  }
  plVar5 = _DAT_23eedec88;
  lVar3 = *(longlong *)(param_1 + 0x38);
  plVar9 = _DAT_23eedec88 + 9;
  lVar4 = *(longlong *)(lVar3 + 8);
  _DAT_23eedec88[0xf] = lVar4;
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
  *(undefined4 *)(plVar5 + 8) = 0;
  plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,uRam000000023eed7458);
  if (plVar9 == (longlong *)0x0) {
LAB_23e871d20:
    plVar10 = *(longlong **)(param_1 + 0x70);
    uVar15 = *(undefined8 *)(param_1 + 0x60);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uVar14 = 0x11f;
    uVar16 = *(undefined8 *)(param_1 + 0x68);
  }
  else {
    plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,uRam000000023eed72d0);
    if (plVar10 != (longlong *)0x0) {
      plVar11 = (longlong *)FUN_23a38cc10(param_1,plVar10,uRam000000023eed7460);
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      if (plVar11 != (longlong *)0x0) {
        plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,uRam000000023eed72c0);
        if (plVar10 == (longlong *)0x0) {
          local_98 = *(undefined8 *)(param_1 + 0x60);
          uStack_90 = *(undefined8 *)(param_1 + 0x68);
          local_88 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          uVar14 = 0x120;
          plVar10 = local_88;
          uVar15 = local_98;
          uVar16 = uStack_90;
          goto LAB_23e871d3e;
        }
        *(undefined4 *)(plVar5 + 5) = 0x11f;
        local_78 = plVar2;
        plStack_70 = plVar11;
        local_68 = plVar10;
        plVar12 = (longlong *)FUN_23e956150(param_1,plVar9,&local_78);
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        if (plVar12 != (longlong *)0x0) {
          plVar9 = (longlong *)FUN_23a388310(plVar12);
          *plVar12 = *plVar12 + -1;
          if (*plVar12 == 0) {
            (**(code **)(plVar12[1] + 0x30))(plVar12);
          }
          if (plVar9 != (longlong *)0x0) {
            plVar11 = (longlong *)(**(code **)(plVar9[1] + 0xe0))(plVar9);
            if ((plVar11 == (longlong *)0x0) &&
               (plVar11 = (longlong *)FUN_23a3c1b70(param_1,&local_98,0,4),
               plVar11 == (longlong *)0x0)) {
              local_a8 = (longlong *)0x0;
              plVar13 = (longlong *)0x0;
              plVar12 = (longlong *)0x0;
            }
            else {
              local_a8 = (longlong *)(**(code **)(plVar9[1] + 0xe0))(plVar9);
              if ((local_a8 == (longlong *)0x0) &&
                 (local_a8 = (longlong *)FUN_23a3c1b70(param_1,&local_98,1,4),
                 local_a8 == (longlong *)0x0)) {
                plVar13 = (longlong *)0x0;
                plVar12 = (longlong *)0x0;
              }
              else {
                plVar12 = (longlong *)(**(code **)(plVar9[1] + 0xe0))(plVar9);
                if ((plVar12 == (longlong *)0x0) &&
                   (plVar12 = (longlong *)FUN_23a3c1b70(param_1,&local_98,2,4),
                   plVar12 == (longlong *)0x0)) {
                  plVar13 = (longlong *)0x0;
                }
                else {
                  plVar13 = (longlong *)(**(code **)(plVar9[1] + 0xe0))(plVar9);
                  if (((plVar13 != (longlong *)0x0) ||
                      (plVar13 = (longlong *)FUN_23a3c1b70(param_1,&local_98,3,4),
                      plVar13 != (longlong *)0x0)) &&
                     (cVar8 = FUN_23a3884a0(param_1,&local_98,plVar9,4), cVar8 != '\0')) {
                    lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                    plVar5 = *(longlong **)(lVar3 + 0x28);
                    plVar10 = (longlong *)plVar5[2];
                    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                         *(undefined8 *)(lVar3 + 0x30);
                    *(undefined4 *)(plVar5 + 8) = 0xffffffff;
                    if (plVar10 != (longlong *)0x0) {
                      plVar5[2] = 0;
                      *plVar10 = *plVar10 + -1;
                      if (*plVar10 == 0) {
                        (**(code **)(plVar10[1] + 0x30))();
                      }
                    }
                    *plVar5 = *plVar5 + -1;
                    if (*plVar5 == 0) {
                      (**(code **)(plVar5[1] + 0x30))(plVar5);
                    }
                    plVar5[0xf] = 0;
                    *plVar9 = *plVar9 + -1;
                    if (*plVar9 == 0) {
                      (**(code **)(plVar9[1] + 0x30))(plVar9);
                    }
                    if (*plVar11 == 0) {
                      (**(code **)(plVar11[1] + 0x30))(plVar11);
                    }
                    if (*local_a8 == 0) {
                      (**(code **)(local_a8[1] + 0x30))();
                    }
                    *plVar12 = *plVar12 + 1;
                    lVar3 = *local_a8;
                    *local_a8 = lVar3 + -1;
                    if (lVar3 + -1 == 0) {
                      (**(code **)(local_a8[1] + 0x30))(local_a8);
                    }
                    *plVar12 = *plVar12 + -1;
                    if (*plVar12 == 0) {
                      (**(code **)(plVar12[1] + 0x30))(plVar12);
                    }
                    if (*plVar13 == 0) {
                      (**(code **)(plVar13[1] + 0x30))(plVar13);
                    }
                    if (*plVar11 == 0) {
                      (**(code **)(plVar11[1] + 0x30))(plVar11);
                    }
                    *plVar12 = *plVar12 + -1;
                    if (*plVar12 == 0) {
                      (**(code **)(plVar12[1] + 0x30))(plVar12);
                    }
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      (**(code **)(plVar13[1] + 0x30))(plVar13);
                    }
                    *plVar1 = *plVar1 + -1;
                    if (*plVar1 == 0) {
                      (**(code **)(plVar1[1] + 0x30))(plVar1);
                    }
                    *plVar2 = *plVar2 + -1;
                    if (*plVar2 != 0) {
                      return plVar11;
                    }
                    (**(code **)(plVar2[1] + 0x30))(plVar2);
                    return plVar11;
                  }
                }
              }
            }
            plVar10 = local_88;
            uVar16 = uStack_90;
            uVar15 = local_98;
            *plVar9 = *plVar9 + -1;
            if (*plVar9 == 0) {
              (**(code **)(plVar9[1] + 0x30))(plVar9);
            }
            local_88 = (longlong *)0x0;
            local_98 = 0;
            uStack_90 = 0;
            if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            if ((local_a8 != (longlong *)0x0) &&
               (lVar3 = *local_a8, *local_a8 = lVar3 + -1, lVar3 + -1 == 0)) {
              (**(code **)(local_a8[1] + 0x30))();
            }
            if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            uVar14 = 0x11f;
            goto LAB_23e871d3e;
          }
        }
        goto LAB_23e871d20;
      }
    }
    local_98 = *(undefined8 *)(param_1 + 0x60);
    uStack_90 = *(undefined8 *)(param_1 + 0x68);
    local_88 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uVar14 = 0x120;
    *plVar9 = *plVar9 + -1;
    plVar10 = local_88;
    uVar15 = local_98;
    uVar16 = uStack_90;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
      uVar14 = 0x120;
      plVar10 = local_88;
      uVar15 = local_98;
      uVar16 = uStack_90;
    }
  }
LAB_23e871d3e:
  plVar9 = DAT_23ed6a4f8;
  uStack_90 = uVar16;
  local_98 = uVar15;
  local_88 = plVar10;
  if (plVar10 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar10 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar10;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    plVar9[2] = 0;
    plVar9[3] = (longlong)plVar5;
    *plVar5 = *plVar5 + 1;
    *(undefined4 *)((longlong)plVar9 + 0x24) = uVar14;
    pcVar7 = _PyRuntime_exref;
    *(undefined4 *)(plVar9 + 4) = 0xffffffff;
    lVar3 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar7 + 0x1f8) + 0x10) + 0x2e8);
    lVar4 = plVar9[-1];
    puVar6 = *(undefined8 **)(lVar3 + 8);
    *puVar6 = plVar9 + -2;
    plVar9[-2] = lVar3;
    plVar9[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar6;
    *(longlong **)(lVar3 + 8) = plVar9 + -2;
    plVar11 = plVar9;
  }
  else {
    plVar11 = plVar10;
    if ((longlong *)plVar10[3] != plVar5) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar11 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar11;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar7 = _PyRuntime_exref;
      plVar9[3] = (longlong)plVar5;
      *plVar5 = *plVar5 + 1;
      lVar3 = *(longlong *)(pcVar7 + 0x1f8);
      *(undefined4 *)((longlong)plVar9 + 0x24) = uVar14;
      *(undefined4 *)(plVar9 + 4) = 0xffffffff;
      lVar3 = *(longlong *)(*(longlong *)(lVar3 + 0x10) + 0x2e8);
      lVar4 = plVar9[-1];
      puVar6 = *(undefined8 **)(lVar3 + 8);
      *puVar6 = plVar9 + -2;
      plVar9[-2] = lVar3;
      plVar9[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar6;
      lVar4 = *plVar10;
      *(longlong **)(lVar3 + 8) = plVar9 + -2;
      plVar9[2] = (longlong)plVar10;
      plVar11 = plVar9;
      if (lVar4 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
    }
  }
  local_88 = plVar11;
  FUN_23e8bba40(plVar5,"ooooo",plVar1,plVar2,0,0,0);
  if (_DAT_23eedec88 == plVar5) {
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))(plVar5);
    }
    _DAT_23eedec88 = (longlong *)0x0;
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
  plVar5 = local_88;
  plVar9[0xf] = 0;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,uVar15,uVar16,plVar5);
  return (longlong *)0x0;
}
