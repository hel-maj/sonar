/* ===== 23aaa9730 __main__:185 ===== */
/* ghidra_name=FUN_23aaa9730 entry=23aaa9730 size=4856 */

code * FUN_23aaa9730(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  undefined8 uVar2;
  longlong *plVar3;
  char cVar4;
  int iVar5;
  longlong lVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong lVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong lVar15;
  undefined4 uVar16;
  code *pcVar17;
  undefined8 *puVar18;
  longlong *plVar19;
  longlong **pplStack_168;
  undefined8 uStack_160;
  longlong *plStack_150;
  undefined8 uStack_148;
  longlong *plStack_140;
  longlong *plStack_130;
  undefined8 uStack_128;
  longlong *plStack_118;
  longlong *plStack_110;
  longlong lStack_108;
  longlong *plStack_100;
  longlong *plStack_f8;
  longlong *plStack_f0;
  longlong *plStack_e8;
  undefined8 *puStack_e0;
  longlong *local_b8;
  longlong *local_b0;
  longlong *local_a8;
  longlong **local_90;
  longlong *local_88;
  undefined8 local_80;
  longlong *local_78;
  undefined8 uStack_70;
  longlong *local_68;
  
  plVar7 = DAT_23ed90c80;
  plVar14 = (longlong *)*param_3;
  plVar1 = (longlong *)param_3[1];
  if (DAT_23ed90c80 == (longlong *)0x0) {
LAB_23aaa9779:
    puStack_e0 = (undefined8 *)0x23aaa9795;
    DAT_23ed90c80 = (longlong *)FUN_23e91f3b0(param_1,DAT_23ed90c78,DAT_23ed90d18,0x28);
  }
  else {
    lVar10 = *DAT_23ed90c80;
    if (1 < lVar10) {
      *DAT_23ed90c80 = lVar10 + -1;
      goto LAB_23aaa9779;
    }
    if (DAT_23ed90c80[2] != 0) {
      *DAT_23ed90c80 = lVar10 + -1;
      if (lVar10 + -1 == 0) {
        puStack_e0 = (undefined8 *)0x23aaa9b02;
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      goto LAB_23aaa9779;
    }
  }
  plVar13 = DAT_23ed90c80;
  lVar10 = *(longlong *)(param_1 + 0x38);
  plVar7 = DAT_23ed90c80 + 9;
  lVar6 = *(longlong *)(lVar10 + 8);
  DAT_23ed90c80[0xf] = lVar6;
  *(longlong **)(lVar10 + 8) = plVar7;
  if ((lVar6 != 0) &&
     (((*(char *)(lVar6 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar6 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar6 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar6 + 0x38))
       ) && (plVar13[0xe] != 0)))) {
    plVar7 = *(longlong **)(lVar6 + 0x28);
    *(longlong **)(plVar13[0xe] + 0x10) = plVar7;
    if (plVar7 != (longlong *)0x0) {
      *plVar7 = *plVar7 + 1;
    }
  }
  *plVar13 = *plVar13 + 1;
  *(undefined4 *)(plVar13 + 8) = 0;
  puStack_e0 = (undefined8 *)0x23aaa9801;
  lVar6 = FUN_23ebc0cf0();
  lVar10 = DAT_23ed8fdb8;
  if (lVar6 == 0) {
    plVar9 = (longlong *)0x0;
    plVar8 = (longlong *)0x0;
    puStack_e0 = (undefined8 *)0x23aaaa2b9;
    FUN_23e915740(param_1,&local_78,DAT_23ed8fba8);
    uVar16 = 0xc3;
    plVar11 = (longlong *)0x0;
    plVar7 = local_68;
    plVar12 = DAT_23ed6a4f8;
    local_90 = (longlong **)uStack_70;
    local_88 = local_78;
    plVar3 = local_80;
    goto joined_r0x00023aaa9f83;
  }
  *(undefined4 *)(plVar13 + 5) = 0xc3;
  puStack_e0 = (undefined8 *)0x23aaa9831;
  plVar7 = (longlong *)FUN_23e915840(param_1,lVar6,DAT_23ed8fbb0,*(undefined8 *)(lVar10 + 0x18));
  if (plVar7 == (longlong *)0x0) {
    local_88 = *(longlong **)(param_1 + 0x60);
    plVar7 = *(longlong **)(param_1 + 0x70);
    plVar9 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar8 = (longlong *)0x0;
    uVar16 = 0xc3;
    local_90 = *(longlong ***)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar11 = (longlong *)0x0;
    plVar12 = DAT_23ed6a4f8;
    plVar3 = local_80;
    goto joined_r0x00023aaa9f83;
  }
  *plVar7 = *plVar7 + -1;
  if (*plVar7 == 0) {
    puStack_e0 = (undefined8 *)0x23aaa9ada;
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  puStack_e0 = (undefined8 *)0x23aaa984f;
  iVar5 = FUN_23a35f020(plVar1);
  if (iVar5 == -1) {
    local_88 = *(longlong **)(param_1 + 0x60);
    plVar7 = *(longlong **)(param_1 + 0x70);
    plVar9 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar16 = 0xc6;
    plVar8 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    local_90 = *(longlong ***)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar12 = DAT_23ed6a4f8;
    plVar3 = local_80;
    goto joined_r0x00023aaa9f83;
  }
  plVar11 = (longlong *)0x0;
  if (iVar5 != 0) {
    puStack_e0 = (undefined8 *)0x23aaa9b15;
    lVar10 = FUN_23ebc0ba0();
    if (lVar10 == 0) {
      plVar9 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      puStack_e0 = (undefined8 *)0x23aaaa611;
      FUN_23e915740(param_1,&local_78,DAT_23ed8fdc0);
      uVar16 = 199;
      plVar11 = (longlong *)0x0;
      plVar7 = local_68;
      plVar12 = DAT_23ed6a4f8;
      local_90 = (longlong **)uStack_70;
      local_88 = local_78;
      plVar3 = local_80;
      goto joined_r0x00023aaa9f83;
    }
    *(undefined4 *)(plVar13 + 5) = 199;
    puStack_e0 = (undefined8 *)0x23aaa9b33;
    plVar11 = (longlong *)FUN_23e91a870(param_1,lVar10);
    if (plVar11 == (longlong *)0x0) {
      local_88 = *(longlong **)(param_1 + 0x60);
      plVar7 = *(longlong **)(param_1 + 0x70);
      plVar9 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar8 = (longlong *)0x0;
      uVar16 = 199;
      local_90 = *(longlong ***)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar12 = DAT_23ed6a4f8;
      plVar3 = local_80;
      goto joined_r0x00023aaa9f83;
    }
    puStack_e0 = (undefined8 *)0x23aaa9b4e;
    plVar12 = (longlong *)FUN_23e8bc2f0(plVar11,DAT_23ed8fdc8);
    if (plVar12 == (longlong *)0x0) {
      local_88 = *(longlong **)(param_1 + 0x60);
      plVar7 = *(longlong **)(param_1 + 0x70);
      plVar8 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar16 = 200;
      local_90 = *(longlong ***)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar9 = (longlong *)0x0;
      plVar12 = DAT_23ed6a4f8;
      plVar3 = local_80;
      goto joined_r0x00023aaa9f83;
    }
    puStack_e0 = (undefined8 *)0x23aaa9b5f;
    lVar10 = FUN_23ebc0ba0();
    if (lVar10 == 0) {
      puStack_e0 = (undefined8 *)0x23aaaa694;
      FUN_23e915740(param_1,&local_78,DAT_23ed8fdc0);
      *plVar12 = *plVar12 + -1;
      lVar10 = *plVar12;
      local_88 = local_78;
      local_90 = (longlong **)uStack_70;
      plVar7 = local_68;
    }
    else {
      puStack_e0 = (undefined8 *)0x23aaa9b7a;
      plVar7 = (longlong *)FUN_23e8bc2f0(lVar10,DAT_23ed8fdd0);
      if (plVar7 != (longlong *)0x0) {
        puStack_e0 = (undefined8 *)0x23aaa9b95;
        plVar9 = (longlong *)FUN_23e8bc2f0(plVar7,DAT_23ed8fdd8);
        *plVar7 = *plVar7 + -1;
        if (*plVar7 == 0) {
          puStack_e0 = (undefined8 *)0x23aaa9ba8;
          (**(code **)(plVar7[1] + 0x30))(plVar7);
        }
        if (plVar9 == (longlong *)0x0) {
          local_88 = *(longlong **)(param_1 + 0x60);
          plVar7 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          local_90 = *(longlong ***)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar12 = *plVar12 + -1;
          if (*plVar12 == 0) {
            plVar8 = (longlong *)0x0;
            plVar9 = (longlong *)0x0;
            puStack_e0 = (undefined8 *)0x23aaaa700;
            (**(code **)(plVar12[1] + 0x30))(plVar12);
            uVar16 = 200;
            plVar12 = DAT_23ed6a4f8;
            plVar3 = local_80;
          }
          else {
            plVar9 = (longlong *)0x0;
            plVar8 = (longlong *)0x0;
            uVar16 = 200;
            plVar12 = DAT_23ed6a4f8;
            plVar3 = local_80;
          }
          goto joined_r0x00023aaa9f83;
        }
        *(undefined4 *)(plVar13 + 5) = 200;
        puStack_e0 = (undefined8 *)0x23aaa9bc6;
        plVar7 = (longlong *)FUN_23e914090(param_1,plVar12,plVar9);
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          puStack_e0 = (undefined8 *)0x23aaa9bda;
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          puStack_e0 = (undefined8 *)0x23aaa9bec;
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        if (plVar7 == (longlong *)0x0) {
          local_88 = *(longlong **)(param_1 + 0x60);
          plVar7 = *(longlong **)(param_1 + 0x70);
          plVar9 = (longlong *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar16 = 200;
          local_90 = *(longlong ***)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar8 = (longlong *)0x0;
          plVar12 = DAT_23ed6a4f8;
          plVar3 = local_80;
          goto joined_r0x00023aaa9f83;
        }
        *plVar7 = *plVar7 + -1;
        if (*plVar7 == 0) {
          puStack_e0 = (undefined8 *)0x23aaaa4aa;
          (**(code **)(plVar7[1] + 0x30))(plVar7);
        }
        lVar10 = DAT_23ed8fde8;
        *(undefined4 *)(plVar13 + 5) = 0xc9;
        puStack_e0 = (undefined8 *)0x23aaa9c23;
        plVar7 = (longlong *)
                 FUN_23e915840(param_1,plVar11,DAT_23ed8fde0,*(undefined8 *)(lVar10 + 0x18));
        if (plVar7 == (longlong *)0x0) {
          local_88 = *(longlong **)(param_1 + 0x60);
          plVar7 = *(longlong **)(param_1 + 0x70);
          plVar9 = (longlong *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar16 = 0xc9;
          local_90 = *(longlong ***)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar8 = (longlong *)0x0;
          plVar12 = DAT_23ed6a4f8;
          plVar3 = local_80;
          goto joined_r0x00023aaa9f83;
        }
        *plVar7 = *plVar7 + -1;
        if (*plVar7 == 0) {
          puStack_e0 = (undefined8 *)0x23aaaa4ca;
          (**(code **)(plVar7[1] + 0x30))(plVar7);
        }
        lVar10 = DAT_23ed8fdf8;
        *(undefined4 *)(plVar13 + 5) = 0xca;
        puStack_e0 = (undefined8 *)0x23aaa9c5d;
        puVar18 = DAT_23ed8fdf0;
        plVar7 = (longlong *)
                 FUN_23e915840(param_1,plVar11,DAT_23ed8fdf0,*(undefined8 *)(lVar10 + 0x18));
        if (plVar7 == (longlong *)0x0) {
          local_88 = *(longlong **)(param_1 + 0x60);
          plVar7 = *(longlong **)(param_1 + 0x70);
          plVar9 = (longlong *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar16 = 0xca;
          local_90 = *(longlong ***)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar8 = (longlong *)0x0;
          plVar12 = DAT_23ed6a4f8;
          plVar3 = local_80;
          goto joined_r0x00023aaa9f83;
        }
        *plVar7 = *plVar7 + -1;
        if (*plVar7 == 0) {
          puStack_e0 = (undefined8 *)0x23aaaa4da;
          (**(code **)(plVar7[1] + 0x30))(plVar7);
        }
        puStack_e0 = (undefined8 *)0x23aaa9c82;
        plVar12 = (longlong *)FUN_23e8bc2f0(plVar11,DAT_23ed8fe00);
        uVar2 = DAT_23ed6cd28;
        if (plVar12 == (longlong *)0x0) {
          local_88 = *(longlong **)(param_1 + 0x60);
          plVar7 = *(longlong **)(param_1 + 0x70);
          plVar8 = (longlong *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar16 = 0xcb;
          local_90 = *(longlong ***)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar9 = (longlong *)0x0;
          plVar12 = DAT_23ed6a4f8;
          plVar3 = local_80;
          goto joined_r0x00023aaa9f83;
        }
        if (DAT_23ed6a4c0 == (longlong *)0x0) {
          puStack_e0 = (undefined8 *)0x23aaaa817;
          plVar7 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
          if (plVar7 == (longlong *)0x0) {
            puStack_e0 = (undefined8 *)0x23aaaaac3;
            PyErr_PrintEx(0,0);
            lVar10 = 1;
            puStack_e0 = (undefined8 *)0x23aaaaace;
            Py_Exit();
            plVar3 = DAT_23ed90c68;
            puStack_e0 = &DAT_23ed6a4c0;
            uStack_128 = uVar2;
            plVar7 = (longlong *)*puVar18;
            plVar8 = (longlong *)puVar18[1];
            plStack_130 = plVar1;
            plStack_118 = plVar13;
            plStack_110 = plVar11;
            lStack_108 = param_1;
            plStack_100 = plVar12;
            plStack_f8 = plVar9;
            plStack_f0 = plVar1;
            plStack_e8 = plVar14;
            if (DAT_23ed90c68 == (longlong *)0x0) {
LAB_23aaaab16:
              DAT_23ed90c68 = (longlong *)FUN_23e91f3b0(lVar10,DAT_23ed90c60,DAT_23ed90d18,0x20);
            }
            else {
              lVar6 = *DAT_23ed90c68;
              if (1 < lVar6) {
                *DAT_23ed90c68 = lVar6 + -1;
                goto LAB_23aaaab16;
              }
              if (DAT_23ed90c68[2] != 0) {
                *DAT_23ed90c68 = lVar6 + -1;
                if (lVar6 + -1 == 0) {
                  (**(code **)(plVar3[1] + 0x30))(plVar3);
                }
                goto LAB_23aaaab16;
              }
            }
            plVar1 = DAT_23ed90c68;
            lVar6 = *(longlong *)(lVar10 + 0x38);
            plVar14 = DAT_23ed90c68 + 9;
            lVar15 = *(longlong *)(lVar6 + 8);
            DAT_23ed90c68[0xf] = lVar15;
            *(longlong **)(lVar6 + 8) = plVar14;
            if (((lVar15 != 0) &&
                ((*(char *)(lVar15 + 0x45) == '\x01' ||
                 ((ulonglong)
                  (*(longlong *)(lVar15 + 0x20) + 0xb8 +
                  (longlong)*(int *)(*(longlong *)(lVar15 + 0x20) + 0xa8) * 2) <=
                  *(ulonglong *)(lVar15 + 0x38))))) && (plVar1[0xe] != 0)) {
              plVar14 = *(longlong **)(lVar15 + 0x28);
              *(longlong **)(plVar1[0xe] + 0x10) = plVar14;
              if (plVar14 != (longlong *)0x0) {
                *plVar14 = *plVar14 + 1;
              }
            }
            *plVar1 = *plVar1 + 1;
            *(undefined4 *)(plVar1 + 8) = 0;
            lVar6 = FUN_23ebc0cf0();
            if (lVar6 == 0) {
              plVar11 = (longlong *)0x0;
              FUN_23e915740(lVar10,&plStack_150,DAT_23ed8fba8);
              uVar16 = 0xe6;
              pplStack_168 = (longlong **)plStack_150;
              uStack_160 = uStack_148;
              plVar13 = (longlong *)0x0;
              plVar14 = plStack_140;
              goto LAB_23aaab0d0;
            }
            plVar13 = (longlong *)FUN_23e8bc2f0(lVar6,DAT_23ed8fbe0);
            plVar14 = DAT_23ed8fe60;
            if (plVar13 == (longlong *)0x0) {
              pplStack_168 = *(longlong ***)(lVar10 + 0x60);
              plVar14 = *(longlong **)(lVar10 + 0x70);
              plVar11 = (longlong *)0x0;
              *(undefined8 *)(lVar10 + 0x70) = 0;
              uVar16 = 0xe6;
              uStack_160 = *(undefined8 *)(lVar10 + 0x68);
              *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23aaab0d0;
            }
            lVar6 = *(longlong *)(lVar10 + 0x10);
            plVar9 = *(longlong **)(lVar6 + 0xe20);
            if (plVar9 == (longlong *)0x0) {
              plVar9 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
            }
            else {
              lVar15 = plVar9[3];
              *(int *)(lVar6 + 0xebc) = *(int *)(lVar6 + 0xebc) + -1;
              *(longlong *)(lVar6 + 0xe20) = lVar15;
              *plVar9 = 1;
            }
            pcVar17 = _PyRuntime_exref;
            plVar11 = (longlong *)&DAT_23ed6a4c0;
            plVar9[4] = 0;
            lVar6 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar17 + 0x1f8) + 0x10) + 0x2e8);
            lVar15 = plVar9[-1];
            puVar18 = *(undefined8 **)(lVar6 + 8);
            *puVar18 = plVar9 + -2;
            plVar9[-2] = lVar6;
            plVar9[-1] = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar18;
            *(longlong **)(lVar6 + 8) = plVar9 + -2;
            plVar12 = DAT_23ed6a4c0;
            *plVar14 = *plVar14 + 1;
            plVar9[3] = (longlong)plVar14;
            uVar2 = DAT_23ed6cd28;
            if (plVar12 == (longlong *)0x0) {
              plVar12 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
              if (plVar12 != (longlong *)0x0) {
                *plVar12 = *plVar12 + 1;
                DAT_23ed6a4c0 = plVar12;
                goto LAB_23aaaac72;
              }
              PyErr_PrintEx(0,0);
              Py_Exit(1);
LAB_23aaab640:
              plVar9 = (longlong *)FUN_23e8bc2f0(plVar11,DAT_23ed8fe78);
              if (plVar9 == (longlong *)0x0) {
LAB_23aaab77c:
                pplStack_168 = *(longlong ***)(lVar10 + 0x60);
                plVar14 = *(longlong **)(lVar10 + 0x70);
                uVar16 = 0xec;
                *(undefined8 *)(lVar10 + 0x70) = 0;
                uStack_160 = *(undefined8 *)(lVar10 + 0x68);
                *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23aaab0d0;
              }
              iVar5 = FUN_23a35f020(plVar9);
              lVar6 = *plVar9 + -1;
              if (iVar5 == -1) {
                pplStack_168 = *(longlong ***)(lVar10 + 0x60);
                plVar14 = *(longlong **)(lVar10 + 0x70);
                *(undefined8 *)(lVar10 + 0x70) = 0;
                uStack_160 = *(undefined8 *)(lVar10 + 0x68);
                *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                *plVar9 = lVar6;
                if (lVar6 == 0) {
                  FUN_23a334bc0();
                }
                uVar16 = 0xec;
                goto LAB_23aaab0d0;
              }
              *plVar9 = lVar6;
              if (lVar6 == 0) {
                (**(code **)(plVar9[1] + 0x30))();
              }
              if (iVar5 == 1) {
                lVar15 = FUN_23ebc0cf0();
                lVar6 = DAT_23ed8fe80;
                if (lVar15 == 0) {
                  FUN_23e915740(lVar10,pplStack_168,DAT_23ed8fba8);
                  uVar16 = 0xed;
                  pplStack_168 = (longlong **)plStack_150;
                  uStack_160 = uStack_148;
                  plVar14 = plStack_140;
                  goto LAB_23aaab0d0;
                }
                *(undefined4 *)(plVar1 + 5) = 0xed;
                plVar14 = (longlong *)
                          FUN_23e915840(lVar10,lVar15,DAT_23ed8fbb0,*(undefined8 *)(lVar6 + 0x18));
                if (plVar14 == (longlong *)0x0) {
                  pplStack_168 = *(longlong ***)(lVar10 + 0x60);
                  plVar14 = *(longlong **)(lVar10 + 0x70);
                  *(undefined8 *)(lVar10 + 0x70) = 0;
                  uVar16 = 0xed;
                  uStack_160 = *(undefined8 *)(lVar10 + 0x68);
                  *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23aaab0d0;
                }
                *plVar14 = *plVar14 + -1;
                if (*plVar14 == 0) {
                  (**(code **)(plVar14[1] + 0x30))(plVar14);
                }
                *(undefined4 *)(plVar1 + 5) = 0xee;
                plVar14 = (longlong *)FUN_23e91bfe0(lVar10,plVar11,DAT_23ed8fe88);
                if (plVar14 == (longlong *)0x0) {
                  pplStack_168 = *(longlong ***)(lVar10 + 0x60);
                  plVar14 = *(longlong **)(lVar10 + 0x70);
                  uVar16 = 0xee;
                  uStack_160 = *(undefined8 *)(lVar10 + 0x68);
                  *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                  *(undefined8 *)(lVar10 + 0x70) = 0;
                  goto LAB_23aaab0d0;
                }
                *plVar14 = *plVar14 + -1;
                if (*plVar14 == 0) {
                  (**(code **)(plVar14[1] + 0x30))(plVar14);
                }
              }
LAB_23aaab020:
              iVar5 = FUN_23e8be270(lVar10,plVar13,DAT_23ed8fe90);
              if (iVar5 == -1) {
                pplStack_168 = *(longlong ***)(lVar10 + 0x60);
                plVar14 = *(longlong **)(lVar10 + 0x70);
                uVar16 = 0xf0;
                *(undefined8 *)(lVar10 + 0x70) = 0;
                uStack_160 = *(undefined8 *)(lVar10 + 0x68);
                *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23aaab0d0;
              }
              if ((iVar5 != 0) &&
                 (cVar4 = FUN_23e8d9ac0(plVar13,DAT_23ed8fe90,_Py_FalseStruct_exref), cVar4 == '\0')
                 ) {
                pplStack_168 = *(longlong ***)(lVar10 + 0x60);
                plVar14 = *(longlong **)(lVar10 + 0x70);
                uVar16 = 0xf1;
                *(undefined8 *)(lVar10 + 0x70) = 0;
                uStack_160 = *(undefined8 *)(lVar10 + 0x68);
                *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23aaab0d0;
              }
LAB_23aaaad65:
              *(undefined4 *)(plVar1 + 5) = 0xf4;
              plVar14 = (longlong *)FUN_23e915840(lVar10,plVar7,DAT_23ed8fe98,plVar8);
              if (plVar14 == (longlong *)0x0) {
                pplStack_168 = *(longlong ***)(lVar10 + 0x60);
                plVar14 = *(longlong **)(lVar10 + 0x70);
                uVar16 = 0xf4;
                *(undefined8 *)(lVar10 + 0x70) = 0;
                uStack_160 = *(undefined8 *)(lVar10 + 0x68);
                *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
              }
              else {
                *plVar14 = *plVar14 + -1;
                if (*plVar14 == 0) {
                  (**(code **)(plVar14[1] + 0x30))(plVar14);
                }
                plVar14 = (longlong *)FUN_23e8bc2f0(plVar7,DAT_23ed8fd68);
                if (plVar14 != (longlong *)0x0) {
                  plVar9 = (longlong *)FUN_23e8bc2f0(plVar14,DAT_23ed8fd70);
                  *plVar14 = *plVar14 + -1;
                  if (*plVar14 == 0) {
                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                  }
                  if (plVar9 != (longlong *)0x0) {
                    *(undefined4 *)(plVar1 + 5) = 0xf7;
                    plVar14 = (longlong *)FUN_23e915840(lVar10,plVar9,DAT_23ed8fea0,plVar8);
                    *plVar9 = *plVar9 + -1;
                    if (*plVar9 == 0) {
                      (**(code **)(plVar9[1] + 0x30))(plVar9);
                    }
                    if (plVar14 != (longlong *)0x0) {
                      *plVar14 = *plVar14 + -1;
                      if (*plVar14 == 0) {
                        (**(code **)(plVar14[1] + 0x30))(plVar14);
                      }
                      lVar6 = *(longlong *)(*(longlong *)(lVar10 + 0x38) + 8);
                      plVar14 = *(longlong **)(lVar6 + 0x28);
                      plVar1 = (longlong *)plVar14[2];
                      *(undefined8 *)(*(longlong *)(lVar10 + 0x38) + 8) =
                           *(undefined8 *)(lVar6 + 0x30);
                      *(undefined4 *)(plVar14 + 8) = 0xffffffff;
                      if (plVar1 != (longlong *)0x0) {
                        plVar14[2] = 0;
                        *plVar1 = *plVar1 + -1;
                        if (*plVar1 == 0) {
                          (**(code **)(plVar1[1] + 0x30))();
                        }
                      }
                      *plVar14 = *plVar14 + -1;
                      if (*plVar14 == 0) {
                        (**(code **)(plVar14[1] + 0x30))(plVar14);
                      }
                      plVar14[0xf] = 0;
                      pcVar17 = _Py_NoneStruct_exref;
                      *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
                      if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0))
                      {
                        (**(code **)(plVar13[1] + 0x30))(plVar13);
                      }
                      if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0))
                      {
                        (**(code **)(plVar11[1] + 0x30))(plVar11);
                      }
                      *plVar7 = *plVar7 + -1;
                      if (*plVar7 == 0) {
                        (**(code **)(plVar7[1] + 0x30))(plVar7);
                      }
                      *plVar8 = *plVar8 + -1;
                      if (*plVar8 == 0) {
                        (**(code **)(plVar8[1] + 0x30))(plVar8);
                        return pcVar17;
                      }
                      return pcVar17;
                    }
                  }
                }
                pplStack_168 = *(longlong ***)(lVar10 + 0x60);
                plVar14 = *(longlong **)(lVar10 + 0x70);
                uVar16 = 0xf7;
                *(undefined8 *)(lVar10 + 0x70) = 0;
                uStack_160 = *(undefined8 *)(lVar10 + 0x68);
                *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
              }
            }
            else {
LAB_23aaaac72:
              pplStack_168 = &plStack_150;
              uStack_148 = uVar2;
              plStack_150 = plVar8;
              lVar6 = FUN_23e94ed00(lVar10,plVar12,pplStack_168);
              if (lVar6 == 0) {
                pplStack_168 = *(longlong ***)(lVar10 + 0x60);
                plVar14 = *(longlong **)(lVar10 + 0x70);
                *(undefined8 *)(lVar10 + 0x70) = 0;
                uStack_160 = *(undefined8 *)(lVar10 + 0x68);
                *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                *plVar13 = *plVar13 + -1;
                if (*plVar13 == 0) {
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                }
                *plVar9 = *plVar9 + -1;
                if (*plVar9 == 0) {
                  (**(code **)(plVar9[1] + 0x30))(plVar9);
                }
              }
              else {
                plVar9[4] = lVar6;
                plVar14 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar9);
                *plVar9 = *plVar9 + -1;
                if (*plVar9 == 0) {
                  (**(code **)(plVar9[1] + 0x30))(plVar9);
                }
                if (plVar14 != (longlong *)0x0) {
                  *(undefined4 *)(plVar1 + 5) = 0xe6;
                  plVar11 = (longlong *)FUN_23e914090(lVar10,plVar13,plVar14);
                  *plVar13 = *plVar13 + -1;
                  if (*plVar13 == 0) {
                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                  }
                  *plVar14 = *plVar14 + -1;
                  if (*plVar14 == 0) {
                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                  }
                  if (plVar11 == (longlong *)0x0) {
                    pplStack_168 = *(longlong ***)(lVar10 + 0x60);
                    plVar14 = *(longlong **)(lVar10 + 0x70);
                    plVar11 = (longlong *)0x0;
                    *(undefined8 *)(lVar10 + 0x70) = 0;
                    uVar16 = 0xe6;
                    uStack_160 = *(undefined8 *)(lVar10 + 0x68);
                    *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                    plVar13 = (longlong *)0x0;
                    goto LAB_23aaab0d0;
                  }
                  *plVar11 = *plVar11 + -1;
                  if (*plVar11 == 0) {
                    (**(code **)(plVar11[1] + 0x30))(plVar11);
                  }
                  plVar13 = (longlong *)FUN_23e8bc2f0(plVar7,DAT_23ed8fd88);
                  if (plVar13 == (longlong *)0x0) {
LAB_23aaab450:
                    pplStack_168 = *(longlong ***)(lVar10 + 0x60);
                    plVar14 = *(longlong **)(lVar10 + 0x70);
                    plVar11 = (longlong *)0x0;
                    *(undefined8 *)(lVar10 + 0x70) = 0;
                    uVar16 = 0xe9;
                    uStack_160 = *(undefined8 *)(lVar10 + 0x68);
                    *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                    plVar13 = (longlong *)0x0;
                    goto LAB_23aaab0d0;
                  }
                  iVar5 = FUN_23a35f020(plVar13);
                  lVar6 = *plVar13 + -1;
                  if (iVar5 == -1) {
                    pplStack_168 = *(longlong ***)(lVar10 + 0x60);
                    plVar14 = *(longlong **)(lVar10 + 0x70);
                    *(undefined8 *)(lVar10 + 0x70) = 0;
                    uStack_160 = *(undefined8 *)(lVar10 + 0x68);
                    *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                    *plVar13 = lVar6;
                    if (lVar6 == 0) {
                      plVar11 = (longlong *)0x0;
                      (**(code **)(plVar13[1] + 0x30))(plVar13);
                      uVar16 = 0xe9;
                      plVar13 = (longlong *)0x0;
                    }
                    else {
                      uVar16 = 0xe9;
                      plVar11 = (longlong *)0x0;
                      plVar13 = (longlong *)0x0;
                    }
                    goto LAB_23aaab0d0;
                  }
                  *plVar13 = lVar6;
                  if (lVar6 == 0) {
                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                  }
                  if (iVar5 != 0) {
                    plVar14 = (longlong *)FUN_23e8bc2f0(plVar7,DAT_23ed8fd88);
                    if (plVar14 == (longlong *)0x0) goto LAB_23aaab450;
                    iVar5 = FUN_23e8be270(lVar10,plVar14,DAT_23ed8fe68);
                    *plVar14 = *plVar14 + -1;
                    if (*plVar14 == 0) {
                      (**(code **)(plVar14[1] + 0x30))(plVar14);
                    }
                    if (iVar5 == -1) {
                      pplStack_168 = *(longlong ***)(lVar10 + 0x60);
                      plVar14 = *(longlong **)(lVar10 + 0x70);
                      plVar11 = (longlong *)0x0;
                      *(undefined8 *)(lVar10 + 0x70) = 0;
                      uVar16 = 0xe9;
                      uStack_160 = *(undefined8 *)(lVar10 + 0x68);
                      *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                      plVar13 = (longlong *)0x0;
                      goto LAB_23aaab0d0;
                    }
                    if (iVar5 != 0) {
                      plVar14 = (longlong *)FUN_23e8bc2f0(plVar7,DAT_23ed8fd88);
                      if (plVar14 == (longlong *)0x0) {
                        pplStack_168 = *(longlong ***)(lVar10 + 0x60);
                        plVar14 = *(longlong **)(lVar10 + 0x70);
                        *(undefined8 *)(lVar10 + 0x70) = 0;
                        uVar16 = 0xea;
                        uStack_160 = *(undefined8 *)(lVar10 + 0x68);
                        *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                        plVar11 = (longlong *)0x0;
                        plVar13 = (longlong *)0x0;
                        goto LAB_23aaab0d0;
                      }
                      plVar13 = (longlong *)FUN_23e8bc2f0(plVar14,DAT_23ed8fe68);
                      *plVar14 = *plVar14 + -1;
                      if (*plVar14 == 0) {
                        (**(code **)(plVar14[1] + 0x30))(plVar14);
                      }
                      if (plVar13 == (longlong *)0x0) {
                        pplStack_168 = *(longlong ***)(lVar10 + 0x60);
                        plVar14 = *(longlong **)(lVar10 + 0x70);
                        plVar11 = (longlong *)0x0;
                        *(undefined8 *)(lVar10 + 0x70) = 0;
                        uVar16 = 0xea;
                        uStack_160 = *(undefined8 *)(lVar10 + 0x68);
                        *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                        goto LAB_23aaab0d0;
                      }
                      plVar11 = (longlong *)
                                FUN_23e8bbbe0(lVar10,plVar13,DAT_23ed8fe70,_Py_NoneStruct_exref);
                      if (plVar11 == (longlong *)0x0) {
                        pplStack_168 = *(longlong ***)(lVar10 + 0x60);
                        plVar14 = *(longlong **)(lVar10 + 0x70);
                        uVar16 = 0xeb;
                        *(undefined8 *)(lVar10 + 0x70) = 0;
                        uStack_160 = *(undefined8 *)(lVar10 + 0x68);
                        *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                        goto LAB_23aaab0d0;
                      }
                      iVar5 = FUN_23a35f020(plVar11);
                      if (iVar5 != -1) {
                        if (iVar5 != 0) goto LAB_23aaab640;
                        goto LAB_23aaab020;
                      }
                      goto LAB_23aaab77c;
                    }
                  }
                  plVar11 = (longlong *)0x0;
                  plVar13 = (longlong *)0x0;
                  goto LAB_23aaaad65;
                }
                pplStack_168 = *(longlong ***)(lVar10 + 0x60);
                plVar14 = *(longlong **)(lVar10 + 0x70);
                *(undefined8 *)(lVar10 + 0x70) = 0;
                uStack_160 = *(undefined8 *)(lVar10 + 0x68);
                *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                *plVar13 = *plVar13 + -1;
                plVar11 = (longlong *)0x0;
                if (*plVar13 == 0) {
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                  uVar16 = 0xe6;
                  plVar13 = (longlong *)0x0;
                  goto LAB_23aaab0d0;
                }
              }
              plVar11 = (longlong *)0x0;
              uVar16 = 0xe6;
              plVar13 = (longlong *)0x0;
            }
LAB_23aaab0d0:
            plVar9 = DAT_23ed6a4f8;
            if (plVar14 == (longlong *)0x0) {
              if (DAT_23ed6a4f8 == (longlong *)0x0) {
                plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
              }
              else {
                plVar14 = (longlong *)*DAT_23ed6a4f8;
                *DAT_23ed6a4f8 = 1;
                DAT_23ed6a4f8 = plVar14;
                DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
              }
              pcVar17 = _PyRuntime_exref;
              plVar9[2] = 0;
              plVar9[3] = (longlong)plVar1;
              *plVar1 = *plVar1 + 1;
              lVar6 = *(longlong *)(pcVar17 + 0x1f8);
              *(undefined4 *)((longlong)plVar9 + 0x24) = uVar16;
              lVar6 = *(longlong *)(lVar6 + 0x10);
              *(undefined4 *)(plVar9 + 4) = 0xffffffff;
              lVar6 = *(longlong *)(lVar6 + 0x2e8);
              lVar15 = plVar9[-1];
              puVar18 = *(undefined8 **)(lVar6 + 8);
              *puVar18 = plVar9 + -2;
              plVar9[-2] = lVar6;
              plVar9[-1] = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar18;
              *(longlong **)(lVar6 + 8) = plVar9 + -2;
              plVar12 = plVar9;
            }
            else {
              plVar12 = plVar14;
              if ((longlong *)plVar14[3] != plVar1) {
                if (DAT_23ed6a4f8 == (longlong *)0x0) {
                  plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
                }
                else {
                  plVar12 = (longlong *)*DAT_23ed6a4f8;
                  *DAT_23ed6a4f8 = 1;
                  DAT_23ed6a4f8 = plVar12;
                  DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                }
                plVar9[3] = (longlong)plVar1;
                *plVar1 = *plVar1 + 1;
                *(undefined4 *)((longlong)plVar9 + 0x24) = uVar16;
                pcVar17 = _PyRuntime_exref;
                *(undefined4 *)(plVar9 + 4) = 0xffffffff;
                lVar6 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar17 + 0x1f8) + 0x10) + 0x2e8);
                lVar15 = plVar9[-1];
                puVar18 = *(undefined8 **)(lVar6 + 8);
                *puVar18 = plVar9 + -2;
                plVar9[-2] = lVar6;
                plVar9[-1] = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar18;
                lVar15 = *plVar14;
                *(longlong **)(lVar6 + 8) = plVar9 + -2;
                plVar9[2] = (longlong)plVar14;
                plVar12 = plVar9;
                if (lVar15 == 0) {
                  (**(code **)(plVar14[1] + 0x30))(plVar14);
                }
              }
            }
            FUN_23e8bba40(plVar1,&DAT_23ec31985,plVar7,plVar8,plVar13,plVar11);
            if (DAT_23ed90c68 == plVar1) {
              *plVar1 = *plVar1 + -1;
              if (*plVar1 == 0) {
                (**(code **)(plVar1[1] + 0x30))(plVar1);
              }
              DAT_23ed90c68 = (longlong *)0x0;
            }
            lVar6 = *(longlong *)(*(longlong *)(lVar10 + 0x38) + 8);
            plVar14 = *(longlong **)(lVar6 + 0x28);
            plVar1 = (longlong *)plVar14[2];
            *(undefined8 *)(*(longlong *)(lVar10 + 0x38) + 8) = *(undefined8 *)(lVar6 + 0x30);
            *(undefined4 *)(plVar14 + 8) = 0xffffffff;
            if (plVar1 != (longlong *)0x0) {
              plVar14[2] = 0;
              *plVar1 = *plVar1 + -1;
              if (*plVar1 == 0) {
                (**(code **)(plVar1[1] + 0x30))();
              }
            }
            *plVar14 = *plVar14 + -1;
            if (*plVar14 == 0) {
              (**(code **)(plVar14[1] + 0x30))(plVar14);
            }
            plVar14[0xf] = 0;
            if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            *plVar7 = *plVar7 + -1;
            if (*plVar7 == 0) {
              (**(code **)(plVar7[1] + 0x30))(plVar7);
            }
            *plVar8 = *plVar8 + -1;
            if (*plVar8 == 0) {
              (**(code **)(plVar8[1] + 0x30))(plVar8);
            }
            FUN_23a33aa70(lVar10,pplStack_168,uStack_160,plVar12);
            return (code *)0x0;
          }
          *plVar7 = *plVar7 + 1;
          DAT_23ed6a4c0 = plVar7;
        }
        local_90 = &local_78;
        uStack_70 = uVar2;
        puStack_e0 = (undefined8 *)0x23aaa9ccb;
        local_78 = plVar1;
        lVar10 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,local_90);
        if (lVar10 != 0) {
          lVar6 = *(longlong *)(param_1 + 0x10);
          plVar7 = *(longlong **)(lVar6 + 0xe20);
          if (plVar7 == (longlong *)0x0) {
            puStack_e0 = (undefined8 *)0x23aaaa529;
            plVar7 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
          }
          else {
            lVar15 = plVar7[3];
            *(int *)(lVar6 + 0xebc) = *(int *)(lVar6 + 0xebc) + -1;
            *(longlong *)(lVar6 + 0xe20) = lVar15;
            *plVar7 = 1;
          }
          lVar6 = *(longlong *)
                   (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
          lVar15 = plVar7[-1];
          puVar18 = *(undefined8 **)(lVar6 + 8);
          *puVar18 = plVar7 + -2;
          plVar9 = DAT_23ed8fe08;
          plVar7[-2] = lVar6;
          plVar7[-1] = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar18;
          *(longlong **)(lVar6 + 8) = plVar7 + -2;
          plVar7[3] = lVar10;
          *plVar9 = *plVar9 + 1;
          plVar7[4] = (longlong)plVar9;
          puStack_e0 = (undefined8 *)0x23aaa9d77;
          plVar9 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar7);
          *plVar7 = *plVar7 + -1;
          if (*plVar7 == 0) {
            puStack_e0 = (undefined8 *)0x23aaa9d8c;
            (**(code **)(plVar7[1] + 0x30))(plVar7);
          }
          if (plVar9 != (longlong *)0x0) {
            *(undefined4 *)(plVar13 + 5) = 0xcb;
            puStack_e0 = (undefined8 *)0x23aaa9daa;
            plVar7 = (longlong *)FUN_23e914090(param_1,plVar12,plVar9);
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
              puStack_e0 = (undefined8 *)0x23aaa9dbe;
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            *plVar9 = *plVar9 + -1;
            if (*plVar9 == 0) {
              puStack_e0 = (undefined8 *)0x23aaa9dce;
              (**(code **)(plVar9[1] + 0x30))(plVar9);
            }
            if (plVar7 == (longlong *)0x0) {
              local_88 = *(longlong **)(param_1 + 0x60);
              plVar7 = *(longlong **)(param_1 + 0x70);
              plVar9 = (longlong *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              plVar8 = (longlong *)0x0;
              uVar16 = 0xcb;
              local_90 = *(longlong ***)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plVar12 = DAT_23ed6a4f8;
              plVar3 = local_80;
              goto joined_r0x00023aaa9f83;
            }
            *plVar7 = *plVar7 + -1;
            if (*plVar7 == 0) {
              puStack_e0 = (undefined8 *)0x23aaa9de9;
              (**(code **)(plVar7[1] + 0x30))(plVar7);
            }
            puStack_e0 = (undefined8 *)0x23aaa9df8;
            plVar12 = (longlong *)FUN_23e8bc2f0(plVar11,DAT_23ed8fe10);
            if (plVar12 == (longlong *)0x0) {
              local_88 = *(longlong **)(param_1 + 0x60);
              plVar7 = *(longlong **)(param_1 + 0x70);
              plVar8 = (longlong *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              uVar16 = 0xd1;
              local_90 = *(longlong ***)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plVar9 = (longlong *)0x0;
              plVar12 = DAT_23ed6a4f8;
              plVar3 = local_80;
              goto joined_r0x00023aaa9f83;
            }
            puStack_e0 = (undefined8 *)0x23aaa9e09;
            lVar10 = FUN_23ebc0ba0();
            if (lVar10 == 0) {
              puStack_e0 = (undefined8 *)0x23aaaa9a1;
              FUN_23e915740(param_1,local_90,DAT_23ed8fdc0);
              *plVar12 = *plVar12 + -1;
              lVar10 = *plVar12;
              local_88 = local_78;
              local_90 = (longlong **)uStack_70;
              plVar7 = local_68;
            }
            else {
              puStack_e0 = (undefined8 *)0x23aaa9e24;
              plVar7 = (longlong *)FUN_23e8bc2f0(lVar10,DAT_23ed8fe18);
              if (plVar7 != (longlong *)0x0) {
                puStack_e0 = (undefined8 *)0x23aaa9e3f;
                plVar9 = (longlong *)FUN_23e8bc2f0(plVar7,DAT_23ed8fe20);
                *plVar7 = *plVar7 + -1;
                if (*plVar7 == 0) {
                  puStack_e0 = (undefined8 *)0x23aaa9e52;
                  (**(code **)(plVar7[1] + 0x30))(plVar7);
                }
                if (plVar9 == (longlong *)0x0) {
                  local_88 = *(longlong **)(param_1 + 0x60);
                  plVar7 = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  local_90 = *(longlong ***)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *plVar12 = *plVar12 + -1;
                  if (*plVar12 == 0) {
                    plVar8 = (longlong *)0x0;
                    plVar9 = (longlong *)0x0;
                    puStack_e0 = (undefined8 *)0x23aaaaa09;
                    (**(code **)(plVar12[1] + 0x30))(plVar12);
                    uVar16 = 0xd1;
                    plVar12 = DAT_23ed6a4f8;
                    plVar3 = local_80;
                  }
                  else {
                    plVar9 = (longlong *)0x0;
                    plVar8 = (longlong *)0x0;
                    uVar16 = 0xd1;
                    plVar12 = DAT_23ed6a4f8;
                    plVar3 = local_80;
                  }
                  goto joined_r0x00023aaa9f83;
                }
                *(undefined4 *)(plVar13 + 5) = 0xd1;
                puStack_e0 = (undefined8 *)0x23aaa9e70;
                plVar7 = (longlong *)FUN_23e914090(param_1,plVar12,plVar9);
                *plVar12 = *plVar12 + -1;
                if (*plVar12 == 0) {
                  puStack_e0 = (undefined8 *)0x23aaa9e84;
                  (**(code **)(plVar12[1] + 0x30))(plVar12);
                }
                *plVar9 = *plVar9 + -1;
                if (*plVar9 == 0) {
                  puStack_e0 = (undefined8 *)0x23aaa9e96;
                  (**(code **)(plVar9[1] + 0x30))(plVar9);
                }
                if (plVar7 == (longlong *)0x0) {
                  local_88 = *(longlong **)(param_1 + 0x60);
                  plVar7 = *(longlong **)(param_1 + 0x70);
                  plVar9 = (longlong *)0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uVar16 = 0xd1;
                  local_90 = *(longlong ***)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  plVar8 = (longlong *)0x0;
                  plVar12 = DAT_23ed6a4f8;
                  plVar3 = local_80;
                  goto joined_r0x00023aaa9f83;
                }
                *plVar7 = *plVar7 + -1;
                if (*plVar7 == 0) {
                  puStack_e0 = (undefined8 *)0x23aaa9eaf;
                  (**(code **)(plVar7[1] + 0x30))(plVar7);
                }
                *(undefined4 *)(plVar13 + 5) = 0xd2;
                puStack_e0 = (undefined8 *)0x23aaa9ec8;
                plVar7 = (longlong *)FUN_23e91bfe0(param_1,plVar11,DAT_23ed8fe28);
                if (plVar7 == (longlong *)0x0) {
                  local_88 = *(longlong **)(param_1 + 0x60);
                  plVar7 = *(longlong **)(param_1 + 0x70);
                  plVar9 = (longlong *)0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uVar16 = 0xd2;
                  local_90 = *(longlong ***)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  plVar8 = (longlong *)0x0;
                  plVar12 = DAT_23ed6a4f8;
                  plVar3 = local_80;
                  goto joined_r0x00023aaa9f83;
                }
                *plVar7 = *plVar7 + -1;
                if (*plVar7 == 0) {
                  puStack_e0 = (undefined8 *)0x23aaa9ee8;
                  (**(code **)(plVar7[1] + 0x30))(plVar7);
                }
                goto LAB_23aaa9862;
              }
              local_88 = *(longlong **)(param_1 + 0x60);
              plVar7 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              local_90 = *(longlong ***)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar12 = *plVar12 + -1;
              lVar10 = *plVar12;
            }
            if (lVar10 == 0) {
              plVar8 = (longlong *)0x0;
              plVar9 = (longlong *)0x0;
              puStack_e0 = (undefined8 *)0x23aaaa983;
              (**(code **)(plVar12[1] + 0x30))(plVar12);
              uVar16 = 0xd1;
              plVar12 = DAT_23ed6a4f8;
              plVar3 = local_80;
            }
            else {
              plVar8 = (longlong *)0x0;
              plVar9 = (longlong *)0x0;
              uVar16 = 0xd1;
              plVar12 = DAT_23ed6a4f8;
              plVar3 = local_80;
            }
            goto joined_r0x00023aaa9f83;
          }
        }
        plVar8 = (longlong *)0x0;
        local_88 = *(longlong **)(param_1 + 0x60);
        plVar7 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        local_90 = *(longlong ***)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          plVar9 = (longlong *)0x0;
          puStack_e0 = (undefined8 *)0x23aaaa74d;
          (**(code **)(plVar12[1] + 0x30))(plVar12);
          uVar16 = 0xcc;
          plVar12 = DAT_23ed6a4f8;
          plVar3 = local_80;
        }
        else {
          plVar9 = (longlong *)0x0;
          uVar16 = 0xcc;
          plVar12 = DAT_23ed6a4f8;
          plVar3 = local_80;
        }
        goto joined_r0x00023aaa9f83;
      }
      local_88 = *(longlong **)(param_1 + 0x60);
      plVar7 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      local_90 = *(longlong ***)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar12 = *plVar12 + -1;
      lVar10 = *plVar12;
    }
    if (lVar10 == 0) {
      plVar8 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      puStack_e0 = (undefined8 *)0x23aaaa671;
      (**(code **)(plVar12[1] + 0x30))(plVar12);
      uVar16 = 200;
      plVar12 = DAT_23ed6a4f8;
      plVar3 = local_80;
    }
    else {
      plVar8 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      uVar16 = 200;
      plVar12 = DAT_23ed6a4f8;
      plVar3 = local_80;
    }
    goto joined_r0x00023aaa9f83;
  }
LAB_23aaa9862:
  lVar10 = *(longlong *)(DAT_23ed8fb58 + 0x20);
  if (*(char *)(lVar10 + 10) == '\0') {
    puStack_e0 = (undefined8 *)0x23aaaa17c;
    plVar7 = (longlong *)FUN_23a37a020(DAT_23ed8fb58,DAT_23ed8fe30);
    if (plVar7 == (longlong *)0x0) goto LAB_23aaa9f19;
    lVar6 = *plVar7;
LAB_23aaaa188:
    if (lVar6 == 0) goto LAB_23aaa9f19;
  }
  else {
    iVar5 = *(int *)(lVar10 + 0xc);
    if (*(int *)(lVar10 + 0xc) == 0) {
      *(int *)(lVar10 + 0xc) = DAT_23ec107d0;
      iVar5 = DAT_23ec107d0;
      DAT_23ec107d0 = DAT_23ec107d0 + 1;
    }
    if (DAT_23ec107ac != iVar5) {
      puStack_e0 = (undefined8 *)0x23aaa9f09;
      DAT_23ec107ac = iVar5;
      DAT_23ed90c70 = FUN_23e8cbd60(lVar10,DAT_23ed8fe30,*(undefined8 *)(DAT_23ed8fe30 + 0x18));
    }
    if (-1 < DAT_23ed90c70) {
      lVar15 = lVar10 + 0x20 + (1L << (*(byte *)(lVar10 + 9) & 0x3f));
      lVar6 = *(longlong *)(lVar15 + 8 + DAT_23ed90c70 * 0x10);
      if (lVar6 != 0) goto LAB_23aaa98cf;
      puStack_e0 = (undefined8 *)0x23aaaa5b3;
      DAT_23ed90c70 = FUN_23e8cbd60(lVar10,DAT_23ed8fe30,*(undefined8 *)(DAT_23ed8fe30 + 0x18));
      if (-1 < DAT_23ed90c70) {
        lVar6 = *(longlong *)(lVar15 + 8 + DAT_23ed90c70 * 0x10);
        goto LAB_23aaaa188;
      }
    }
LAB_23aaa9f19:
    puStack_e0 = (undefined8 *)0x23aaa9f2f;
    plVar7 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23ed8fe30);
    if ((plVar7 == (longlong *)0x0) || (lVar6 = *plVar7, lVar6 == 0)) {
      plVar9 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      puStack_e0 = (undefined8 *)0x23aaa9f59;
      FUN_23e915740(param_1,&local_78,DAT_23ed8fe30);
      uVar16 = 0xd5;
      plVar7 = local_68;
      plVar12 = DAT_23ed6a4f8;
      local_90 = (longlong **)uStack_70;
      local_88 = local_78;
      plVar3 = local_80;
      goto joined_r0x00023aaa9f83;
    }
  }
LAB_23aaa98cf:
  puStack_e0 = (undefined8 *)0x23aaa98de;
  plVar7 = (longlong *)FUN_23e8bc2f0(plVar14,DAT_23ed8fd58);
  if (plVar7 == (longlong *)0x0) {
    local_88 = *(longlong **)(param_1 + 0x60);
    plVar7 = *(longlong **)(param_1 + 0x70);
    plVar8 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar16 = 0xd5;
    local_90 = *(longlong ***)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar9 = (longlong *)0x0;
    plVar12 = DAT_23ed6a4f8;
    plVar3 = local_80;
  }
  else {
    *(undefined4 *)(plVar13 + 5) = 0xd5;
    puStack_e0 = (undefined8 *)0x23aaa98ff;
    plVar8 = (longlong *)FUN_23e914090(param_1,lVar6,plVar7);
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      puStack_e0 = (undefined8 *)0x23aaaa14a;
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    if (plVar8 == (longlong *)0x0) {
      local_88 = *(longlong **)(param_1 + 0x60);
      plVar7 = *(longlong **)(param_1 + 0x70);
      plVar9 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar16 = 0xd5;
      local_90 = *(longlong ***)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar12 = DAT_23ed6a4f8;
      plVar3 = local_80;
    }
    else {
      *(undefined4 *)(plVar13 + 5) = 0xd6;
      puStack_e0 = (undefined8 *)0x23aaa992f;
      plVar9 = (longlong *)FUN_23e91bfe0(param_1,plVar8,DAT_23ed8fe28);
      if (plVar9 == (longlong *)0x0) {
        local_88 = *(longlong **)(param_1 + 0x60);
        plVar7 = *(longlong **)(param_1 + 0x70);
        uVar16 = 0xd6;
        *(undefined8 *)(param_1 + 0x70) = 0;
        local_90 = *(longlong ***)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar12 = DAT_23ed6a4f8;
        plVar3 = local_80;
      }
      else {
        puStack_e0 = (undefined8 *)0x23aaa994a;
        plVar7 = (longlong *)FUN_23e8bc2f0(plVar8,DAT_23ed8fe38);
        if (plVar7 != (longlong *)0x0) {
          puStack_e0 = (undefined8 *)0x23aaa9965;
          local_90 = (longlong **)FUN_23e8bc2f0(plVar7,DAT_23ed8fe40);
          *plVar7 = *plVar7 + -1;
          if (*plVar7 == 0) {
            puStack_e0 = (undefined8 *)0x23aaaa160;
            (**(code **)(plVar7[1] + 0x30))(plVar7);
          }
          if (local_90 != (longlong **)0x0) {
            puStack_e0 = (undefined8 *)0x23aaa998c;
            iVar5 = FUN_23e912620(plVar9,local_90);
            *local_90 = (longlong *)((longlong)*local_90 + -1);
            if (*local_90 == (longlong *)0x0) {
              puStack_e0 = (undefined8 *)0x23aaa99a4;
              (**(code **)((longlong)local_90[1] + 0x30))(local_90);
            }
            if (iVar5 != -1) {
              if (iVar5 == 1) {
                puStack_e0 = (undefined8 *)0x23aaaa3b5;
                lVar6 = FUN_23ebc0cf0();
                lVar10 = DAT_23ed8fe48;
                if (lVar6 == 0) {
                  puStack_e0 = (undefined8 *)0x23aaaa927;
                  FUN_23e915740(param_1,&local_78,DAT_23ed8fba8);
                  uVar16 = 0xd9;
                  plVar7 = local_68;
                  plVar12 = DAT_23ed6a4f8;
                  local_90 = (longlong **)uStack_70;
                  local_88 = local_78;
                  plVar3 = local_80;
                }
                else {
                  *(undefined4 *)(plVar13 + 5) = 0xd9;
                  puStack_e0 = (undefined8 *)0x23aaaa3e2;
                  plVar7 = (longlong *)
                           FUN_23e915840(param_1,lVar6,DAT_23ed8fbb0,*(undefined8 *)(lVar10 + 0x18))
                  ;
                  if (plVar7 != (longlong *)0x0) {
                    *plVar7 = *plVar7 + -1;
                    if (*plVar7 == 0) {
                      puStack_e0 = (undefined8 *)0x23aaaa3fb;
                      (**(code **)(plVar7[1] + 0x30))(plVar7);
                    }
                    pcVar17 = _Py_TrueStruct_exref;
                    *(longlong *)_Py_TrueStruct_exref = *(longlong *)_Py_TrueStruct_exref + 1;
                    goto LAB_23aaa9a0b;
                  }
                  local_88 = *(longlong **)(param_1 + 0x60);
                  plVar7 = *(longlong **)(param_1 + 0x70);
                  uVar16 = 0xd9;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  local_90 = *(longlong ***)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  plVar12 = DAT_23ed6a4f8;
                  plVar3 = local_80;
                }
              }
              else {
                puStack_e0 = (undefined8 *)0x23aaa99bd;
                lVar6 = FUN_23ebc0cf0();
                lVar10 = DAT_23ed8fe50;
                if (lVar6 == 0) {
                  puStack_e0 = (undefined8 *)0x23aaaa7dc;
                  FUN_23e915740(param_1,&local_78,DAT_23ed8fba8);
                  uVar16 = 0xdc;
                  plVar7 = local_68;
                  plVar12 = DAT_23ed6a4f8;
                  local_90 = (longlong **)uStack_70;
                  local_88 = local_78;
                  plVar3 = local_80;
                }
                else {
                  *(undefined4 *)(plVar13 + 5) = 0xdc;
                  puStack_e0 = (undefined8 *)0x23aaa99ea;
                  plVar7 = (longlong *)
                           FUN_23e915840(param_1,lVar6,DAT_23ed8fbb0,*(undefined8 *)(lVar10 + 0x18))
                  ;
                  if (plVar7 != (longlong *)0x0) {
                    *plVar7 = *plVar7 + -1;
                    if (*plVar7 == 0) {
                      puStack_e0 = (undefined8 *)0x23aaaa4b7;
                      (**(code **)(plVar7[1] + 0x30))(plVar7);
                    }
                    pcVar17 = _Py_FalseStruct_exref;
                    *(longlong *)_Py_FalseStruct_exref = *(longlong *)_Py_FalseStruct_exref + 1;
LAB_23aaa9a0b:
                    lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                    plVar7 = *(longlong **)(lVar10 + 0x28);
                    plVar13 = (longlong *)plVar7[2];
                    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                         *(undefined8 *)(lVar10 + 0x30);
                    *(undefined4 *)(plVar7 + 8) = 0xffffffff;
                    if (plVar13 != (longlong *)0x0) {
                      plVar7[2] = 0;
                      *plVar13 = *plVar13 + -1;
                      if (*plVar13 == 0) {
                        puStack_e0 = (undefined8 *)0x23aaaa497;
                        (**(code **)(plVar13[1] + 0x30))();
                      }
                    }
                    *plVar7 = *plVar7 + -1;
                    if (*plVar7 == 0) {
                      puStack_e0 = (undefined8 *)0x23aaa9a51;
                      (**(code **)(plVar7[1] + 0x30))(plVar7);
                    }
                    plVar7[0xf] = 0;
                    if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
                      puStack_e0 = (undefined8 *)0x23aaaa48a;
                      (**(code **)(plVar11[1] + 0x30))(plVar11);
                    }
                    *plVar8 = *plVar8 + -1;
                    if (*plVar8 == 0) {
                      puStack_e0 = (undefined8 *)0x23aaa9a78;
                      (**(code **)(plVar8[1] + 0x30))(plVar8);
                    }
                    *plVar9 = *plVar9 + -1;
                    if (*plVar9 == 0) {
                      puStack_e0 = (undefined8 *)0x23aaa9a89;
                      (**(code **)(plVar9[1] + 0x30))(plVar9);
                    }
                    *plVar14 = *plVar14 + -1;
                    if (*plVar14 == 0) {
                      puStack_e0 = (undefined8 *)0x23aaa9a99;
                      (**(code **)(plVar14[1] + 0x30))(plVar14);
                    }
                    *plVar1 = *plVar1 + -1;
                    if (*plVar1 == 0) {
                      puStack_e0 = (undefined8 *)0x23aaa9aaa;
                      (**(code **)(plVar1[1] + 0x30))(plVar1);
                      return pcVar17;
                    }
                    return pcVar17;
                  }
                  local_88 = *(longlong **)(param_1 + 0x60);
                  plVar7 = *(longlong **)(param_1 + 0x70);
                  uVar16 = 0xdc;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  local_90 = *(longlong ***)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  plVar12 = DAT_23ed6a4f8;
                  plVar3 = local_80;
                }
              }
              goto joined_r0x00023aaa9f83;
            }
          }
        }
        local_88 = *(longlong **)(param_1 + 0x60);
        plVar7 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar16 = 0xd8;
        local_90 = *(longlong ***)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar12 = DAT_23ed6a4f8;
        plVar3 = local_80;
      }
    }
  }
joined_r0x00023aaa9f83:
  local_80._4_4_ = (undefined4)((ulonglong)plVar3 >> 0x20);
  DAT_23ed6a4f8 = plVar12;
  local_80 = plVar3;
  if (plVar7 == (longlong *)0x0) {
    if (plVar12 == (longlong *)0x0) {
      local_80 = (longlong *)CONCAT44(local_80._4_4_,uVar16);
      puStack_e0 = (undefined8 *)0x23aaaa5e8;
      plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      uVar16 = SUB84(local_80,0);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar12;
      *plVar12 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar17 = _PyRuntime_exref;
    plVar12[3] = (longlong)plVar13;
    plVar12[2] = 0;
    *plVar13 = *plVar13 + 1;
    lVar10 = *(longlong *)(pcVar17 + 0x1f8);
    *(undefined4 *)((longlong)plVar12 + 0x24) = uVar16;
    *(undefined4 *)(plVar12 + 4) = 0xffffffff;
    lVar10 = *(longlong *)(*(longlong *)(lVar10 + 0x10) + 0x2e8);
    lVar6 = plVar12[-1];
    puVar18 = *(undefined8 **)(lVar10 + 8);
    *puVar18 = plVar12 + -2;
    plVar12[-2] = lVar10;
    plVar12[-1] = (ulonglong)((uint)lVar6 & 3) | (ulonglong)puVar18;
    *(longlong **)(lVar10 + 8) = plVar12 + -2;
    plVar19 = plVar12;
    plVar3 = local_80;
  }
  else {
    plVar19 = plVar7;
    if ((longlong *)plVar7[3] != plVar13) {
      if (plVar12 == (longlong *)0x0) {
        local_80 = (longlong *)CONCAT44(local_80._4_4_,uVar16);
        puStack_e0 = (undefined8 *)0x23aaaa3a0;
        plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
        uVar16 = SUB84(local_80,0);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar12;
        *plVar12 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar12[3] = (longlong)plVar13;
      *plVar13 = *plVar13 + 1;
      *(undefined4 *)((longlong)plVar12 + 0x24) = uVar16;
      pcVar17 = _PyRuntime_exref;
      *(undefined4 *)(plVar12 + 4) = 0xffffffff;
      lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar17 + 0x1f8) + 0x10) + 0x2e8);
      lVar6 = plVar12[-1];
      puVar18 = *(undefined8 **)(lVar10 + 8);
      *puVar18 = plVar12 + -2;
      plVar12[-2] = lVar10;
      plVar12[-1] = (ulonglong)((uint)lVar6 & 3) | (ulonglong)puVar18;
      lVar6 = *plVar7;
      *(longlong **)(lVar10 + 8) = plVar12 + -2;
      plVar12[2] = (longlong)plVar7;
      plVar19 = plVar12;
      plVar3 = local_80;
      if (lVar6 == 0) {
        puStack_e0 = (undefined8 *)0x23aaaa02f;
        local_80 = plVar12;
        (**(code **)(plVar7[1] + 0x30))(plVar7);
        plVar19 = local_80;
        plVar3 = local_80;
      }
    }
  }
  local_80 = plVar3;
  puStack_e0 = (undefined8 *)0x23aaaa05b;
  local_b8 = plVar11;
  local_b0 = plVar8;
  local_a8 = plVar9;
  FUN_23e8bba40(plVar13,"ooooo",plVar14,plVar1);
  if (DAT_23ed90c80 == plVar13) {
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      puStack_e0 = (undefined8 *)0x23aaaa290;
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
    DAT_23ed90c80 = (longlong *)0x0;
  }
  lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar7 = *(longlong **)(lVar10 + 0x28);
  plVar13 = (longlong *)plVar7[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
  *(undefined4 *)(plVar7 + 8) = 0xffffffff;
  if (plVar13 != (longlong *)0x0) {
    plVar7[2] = 0;
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      puStack_e0 = (undefined8 *)0x23aaaa0a1;
      (**(code **)(plVar13[1] + 0x30))();
    }
  }
  *plVar7 = *plVar7 + -1;
  if (*plVar7 == 0) {
    puStack_e0 = (undefined8 *)0x23aaaa0b1;
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  plVar7[0xf] = 0;
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    puStack_e0 = (undefined8 *)0x23aaaa0ce;
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    puStack_e0 = (undefined8 *)0x23aaaa0e3;
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    puStack_e0 = (undefined8 *)0x23aaaa0f9;
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  *plVar14 = *plVar14 + -1;
  if (*plVar14 == 0) {
    puStack_e0 = (undefined8 *)0x23aaaa109;
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    puStack_e0 = (undefined8 *)0x23aaaa11a;
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  puStack_e0 = (undefined8 *)0x23aaaa131;
  FUN_23a33aa70(param_1,local_88,local_90,plVar19);
  return (code *)0x0;
}
