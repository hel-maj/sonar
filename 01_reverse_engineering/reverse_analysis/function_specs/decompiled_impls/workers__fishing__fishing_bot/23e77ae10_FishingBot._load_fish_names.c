/* ===== 23e77ae10 workers.fishing.fishing_bot:FishingBot._load_fish_names ===== */
/* ghidra_name=FUN_23e77ae10 entry=23e77ae10 size=13731 */

/* WARNING: Restarted to delay deadcode elimination for space: ram */

code * FUN_23e77ae10(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  bool bVar4;
  char cVar5;
  int iVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong lVar9;
  undefined8 uVar10;
  code *pcVar11;
  code *pcVar12;
  code *pcVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  longlong *plVar17;
  longlong *plVar18;
  longlong *plVar19;
  longlong lVar20;
  longlong *plVar21;
  longlong *plVar22;
  longlong *plVar23;
  code *pcVar24;
  longlong *plVar25;
  undefined1 auVar26 [8];
  undefined4 uVar27;
  code *pcVar28;
  longlong *local_140;
  longlong *local_138;
  longlong *local_130;
  code *local_128;
  longlong *local_118;
  longlong *local_108;
  code *local_e8;
  undefined8 uStack_e0;
  undefined1 local_d8 [16];
  code *local_c8 [2];
  undefined1 local_b8 [16];
  code *local_a8 [2];
  undefined1 local_98 [8];
  code *pcStack_90;
  code *local_88 [2];
  code *local_78;
  code *pcStack_70;
  code *local_68;
  
  plVar7 = DAT_23eedad30;
  plVar1 = (longlong *)*param_3;
  local_88[0] = (code *)0x0;
  local_98 = (undefined1  [8])0x0;
  pcStack_90 = (code *)0x0;
  if (DAT_23eedad30 == (longlong *)0x0) {
LAB_23e77ae6d:
    DAT_23eedad30 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eedaf30,DAT_23eedaeb8,0x40);
  }
  else {
    lVar20 = *DAT_23eedad30;
    if (1 < lVar20) {
      *DAT_23eedad30 = lVar20 + -1;
      goto LAB_23e77ae6d;
    }
    if (DAT_23eedad30[2] != 0) {
      *DAT_23eedad30 = lVar20 + -1;
      if (lVar20 + -1 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      goto LAB_23e77ae6d;
    }
  }
  plVar2 = DAT_23eedad30;
  lVar20 = *(longlong *)(param_1 + 0x38);
  plVar7 = DAT_23eedad30 + 9;
  lVar9 = *(longlong *)(lVar20 + 8);
  DAT_23eedad30[0xf] = lVar9;
  *(longlong **)(lVar20 + 8) = plVar7;
  if ((lVar9 != 0) &&
     (((*(char *)(lVar9 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar9 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar9 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar9 + 0x38))
       ) && (plVar2[0xe] != 0)))) {
    plVar7 = *(longlong **)(lVar9 + 0x28);
    *(longlong **)(plVar2[0xe] + 0x10) = plVar7;
    if (plVar7 != (longlong *)0x0) {
      *plVar7 = *plVar7 + 1;
    }
  }
  lVar9 = DAT_23eed8950;
  *plVar2 = *plVar2 + 1;
  *(undefined4 *)(plVar2 + 8) = 0;
  lVar20 = *(longlong *)(lVar9 + 0x20);
  if (*(char *)(lVar20 + 10) == '\0') {
    plVar7 = (longlong *)FUN_23a37a020(lVar9,DAT_23eed9758);
    if (plVar7 == (longlong *)0x0) goto LAB_23e77b1c9;
    lVar20 = *plVar7;
LAB_23e77c118:
    if (lVar20 == 0) goto LAB_23e77b1c9;
LAB_23e77af5d:
    *(undefined4 *)(plVar2 + 5) = 0x63b;
    plVar7 = (longlong *)FUN_23e91a870();
    if (plVar7 == (longlong *)0x0) {
LAB_23e77b240:
      local_88[0] = *(code **)(param_1 + 0x70);
      local_98 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_90 = *(code **)(param_1 + 0x68);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e77b269;
    }
    plVar8 = (longlong *)FUN_23e8bc2f0(plVar7,DAT_23ed6cfb0);
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))();
    }
    if (plVar8 == (longlong *)0x0) goto LAB_23e77b240;
    plVar7 = (longlong *)FUN_23e8c6f80(plVar8,DAT_23eed9760);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))();
    }
    if (plVar7 == (longlong *)0x0) goto LAB_23e77b240;
    plVar8 = (longlong *)FUN_23e8c6f80(plVar7,DAT_23eed9768);
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))();
    }
    if (plVar8 == (longlong *)0x0) goto LAB_23e77b240;
    *(undefined4 *)(plVar2 + 5) = 0x63c;
    plVar7 = (longlong *)FUN_23e91bfe0(param_1,plVar8);
    if (plVar7 == (longlong *)0x0) {
      local_88[0] = *(code **)(param_1 + 0x70);
      local_98 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_90 = *(code **)(param_1 + 0x68);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e77bd39:
      local_138 = (longlong *)0x0;
      iVar6 = 0x63c;
      plVar23 = (longlong *)0x0;
      plVar7 = (longlong *)0x0;
      local_130 = (longlong *)0x0;
      local_140 = (longlong *)0x0;
      pcVar28 = _Py_NoneStruct_exref;
      goto LAB_23e77b29a;
    }
    iVar6 = FUN_23a35f020();
    lVar20 = *plVar7 + -1;
    if (iVar6 == -1) {
      local_98 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_90 = *(code **)(param_1 + 0x68);
      local_88[0] = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar7 = lVar20;
      if (lVar20 == 0) {
        (**(code **)(plVar7[1] + 0x30))();
      }
      goto LAB_23e77bd39;
    }
    *plVar7 = lVar20;
    if (lVar20 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    if (iVar6 == 0) {
      local_138 = (longlong *)0x0;
      plVar23 = (longlong *)0x0;
      plVar7 = (longlong *)0x0;
      local_130 = (longlong *)0x0;
      local_140 = (longlong *)0x0;
      pcVar28 = _Py_NoneStruct_exref;
      goto LAB_23e77b090;
    }
    plVar14 = (longlong *)FUN_23e91c870(param_1,plVar8);
    pcVar28 = _Py_NoneStruct_exref;
    if (plVar14 != (longlong *)0x0) {
      plVar7 = (longlong *)FUN_23e8d9880();
      if (plVar7 == (longlong *)0x0) {
        local_128 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        auVar26 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcVar13 = *(code **)(param_1 + 0x68);
        lVar20 = *plVar14;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar14 = lVar20 + -1;
        if (lVar20 + -1 == 0) {
LAB_23e77d423:
          pcStack_90 = (code *)0x0;
          local_98 = (undefined1  [8])0x0;
          local_88[0] = (code *)0x0;
          plVar23 = (longlong *)0x0;
          plVar7 = (longlong *)0x0;
          (**(code **)(plVar14[1] + 0x30))();
          local_138 = (longlong *)0x0;
          iVar6 = 0x63d;
          local_130 = (longlong *)0x0;
          local_140 = (longlong *)0x0;
          pcVar28 = _Py_NoneStruct_exref;
        }
        else {
          plVar23 = (longlong *)0x0;
          iVar6 = 0x63d;
          local_138 = (longlong *)0x0;
          local_130 = (longlong *)0x0;
          local_140 = (longlong *)0x0;
          plVar7 = (longlong *)0x0;
          pcVar28 = _Py_NoneStruct_exref;
        }
        goto LAB_23e77d29d;
      }
      *(undefined4 *)(plVar2 + 5) = 0x63d;
      plVar15 = (longlong *)FUN_23e91a870();
      *plVar7 = *plVar7 + -1;
      if (*plVar7 == 0) {
        (**(code **)(plVar7[1] + 0x30))();
      }
      if (plVar15 == (longlong *)0x0) {
        local_128 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        auVar26 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcVar13 = *(code **)(param_1 + 0x68);
        lVar20 = *plVar14;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar14 = lVar20 + -1;
        if (lVar20 + -1 == 0) goto LAB_23e77d423;
LAB_23e77d4a0:
        local_138 = (longlong *)0x0;
        plVar23 = (longlong *)0x0;
        plVar7 = (longlong *)0x0;
        local_130 = (longlong *)0x0;
        iVar6 = 0x63d;
        local_140 = (longlong *)0x0;
        pcVar28 = _Py_NoneStruct_exref;
        goto LAB_23e77d29d;
      }
      plVar16 = (longlong *)FUN_23e8d9880(plVar14,DAT_23ed6cd98);
      if (plVar16 != (longlong *)0x0) {
        *plVar15 = *plVar15 + 1;
        plVar17 = (longlong *)FUN_23ebf7180(plVar15);
        local_140 = plVar15;
        if (plVar17 != (longlong *)0x0) {
          plVar19 = (longlong *)0x0;
          if (plVar1 != (longlong *)0x0) {
            plVar7 = (longlong *)0x0;
            local_138 = (longlong *)0x0;
            lVar20 = plVar17[1];
            local_118 = (longlong *)0x0;
            pcVar28 = *(code **)(lVar20 + 0xe0);
            local_108 = (longlong *)0x0;
            plVar25 = local_138;
            plVar23 = local_108;
joined_r0x00023e77c4a8:
            local_138 = plVar25;
            if (pcVar28 == (code *)0x0) goto LAB_23e77c5e2;
            plVar18 = (longlong *)(*pcVar28)(plVar17);
            if (plVar18 == (longlong *)0x0) goto LAB_23e77c607;
            if ((plVar19 != (longlong *)0x0) && (*plVar19 = *plVar19 + -1, *plVar19 == 0)) {
              (**(code **)(plVar19[1] + 0x30))(plVar19);
            }
            *plVar18 = *plVar18 + 1;
            if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
              (**(code **)(plVar7[1] + 0x30))(plVar7);
            }
            plVar19 = (longlong *)FUN_23e8bc2f0(plVar18,DAT_23eed9778);
            if (plVar19 == (longlong *)0x0) goto LAB_23e77d6af;
            *(undefined4 *)(plVar2 + 5) = 0x63f;
            plVar7 = (longlong *)FUN_23e91a870(param_1,plVar19);
            *plVar19 = *plVar19 + -1;
            if (*plVar19 == 0) {
              (**(code **)(plVar19[1] + 0x30))(plVar19);
            }
            lVar20 = *plVar18;
            if (plVar7 == (longlong *)0x0) goto LAB_23e77d6af;
            *plVar18 = lVar20 + -1;
            if (lVar20 + -1 == 0) {
              (**(code **)(plVar18[1] + 0x30))(plVar18);
            }
            iVar6 = FUN_23a35f020(plVar7);
            if (iVar6 == -1) goto LAB_23e77d860;
            local_108 = plVar23;
            if (iVar6 == 0) {
LAB_23e77c56c:
              lVar20 = *(longlong *)(param_1 + 0x10);
              if ((((*(int *)(*(longlong *)(lVar20 + 0x28) + 0x160) != 0) ||
                   (*(int *)(lVar20 + 0x78) != 0)) && (iVar6 = Py_MakePendingCalls(), iVar6 < 0)) &&
                 (*(longlong *)(param_1 + 0x60) != 0)) goto LAB_23e77cd65;
              if (*(int *)(lVar20 + 0x68) == 0) {
                plVar23 = *(longlong **)(param_1 + 0x90);
              }
              else {
                PyEval_SaveThread();
                PyEval_AcquireThread(param_1);
                plVar23 = *(longlong **)(param_1 + 0x90);
              }
              if (plVar23 != (longlong *)0x0) goto LAB_23e77cce5;
              lVar20 = plVar17[1];
              pcVar28 = *(code **)(lVar20 + 0xe0);
              plVar19 = plVar18;
              plVar25 = local_138;
              plVar23 = local_108;
              goto joined_r0x00023e77c4a8;
            }
            iVar6 = PySequence_Contains(plVar7,DAT_23eed9780);
            if (iVar6 == -1) goto LAB_23e77d860;
            if (iVar6 != 1) goto LAB_23e77c56c;
            plVar19 = (longlong *)FUN_23e8bc2f0(plVar7,DAT_23ed6d020);
            if (plVar19 == (longlong *)0x0) goto LAB_23e77dce3;
            *(undefined4 *)(plVar2 + 5) = 0x641;
            plVar21 = (longlong *)FUN_23e9557e0(param_1,plVar19,DAT_23eed9788);
            *plVar19 = *plVar19 + -1;
            if (*plVar19 == 0) {
              (**(code **)(plVar19[1] + 0x30))(plVar19);
            }
            if (plVar21 == (longlong *)0x0) goto LAB_23e77e20b;
            plVar22 = (longlong *)FUN_23a388310(plVar21);
            *plVar21 = *plVar21 + -1;
            if (*plVar21 == 0) {
              (**(code **)(plVar21[1] + 0x30))(plVar21);
            }
            if (plVar22 == (longlong *)0x0) goto LAB_23e77dce3;
            local_108 = (longlong *)(**(code **)(plVar22[1] + 0xe0))(plVar22);
            if ((local_108 != (longlong *)0x0) ||
               (local_108 = (longlong *)FUN_23a3c1b70(param_1,local_98,0,2),
               local_108 != (longlong *)0x0)) {
              local_130 = (longlong *)(**(code **)(plVar22[1] + 0xe0))(plVar22);
              if ((local_130 == (longlong *)0x0) &&
                 (local_130 = (longlong *)FUN_23a3c1b70(param_1,local_98,1,2),
                 local_130 == (longlong *)0x0)) goto LAB_23e77d9da;
              cVar5 = FUN_23a3884a0(param_1,local_98,plVar22);
              lVar20 = *plVar22;
              if (cVar5 == '\0') goto LAB_23e77d9da;
              *plVar22 = lVar20 + -1;
              if (lVar20 + -1 == 0) {
                (**(code **)(plVar22[1] + 0x30))(plVar22);
              }
              lVar20 = *local_108;
              *local_108 = lVar20 + 1;
              if (plVar23 != (longlong *)0x0) {
                lVar20 = *plVar23;
                *plVar23 = lVar20 + -1;
                if (lVar20 + -1 == 0) {
                  (**(code **)(plVar23[1] + 0x30))(plVar23);
                  lVar20 = *local_108 + -1;
                }
                else {
                  lVar20 = *local_108 + -1;
                }
              }
              *local_108 = lVar20;
              if (lVar20 == 0) {
                (**(code **)(local_108[1] + 0x30))(local_108);
              }
              lVar20 = *local_130;
              *local_130 = lVar20 + 1;
              if (local_118 != (longlong *)0x0) {
                lVar20 = *local_118;
                *local_118 = lVar20 + -1;
                if (lVar20 + -1 == 0) {
                  (**(code **)(local_118[1] + 0x30))(local_118);
                  lVar20 = *local_130 + -1;
                }
                else {
                  lVar20 = *local_130 + -1;
                }
              }
              *local_130 = lVar20;
              if (lVar20 == 0) {
                (**(code **)(local_130[1] + 0x30))(local_130);
              }
              plVar23 = (longlong *)FUN_23e8bc2f0(local_108,DAT_23eed9790);
              uVar10 = DAT_23eed9798;
              if (plVar23 == (longlong *)0x0) goto LAB_23e77dbad;
              *(undefined4 *)(plVar2 + 5) = 0x643;
              local_138 = (longlong *)FUN_23e9557e0(param_1,plVar23,uVar10);
              *plVar23 = *plVar23 + -1;
              if (*plVar23 == 0) {
                (**(code **)(plVar23[1] + 0x30))(plVar23);
              }
              if (local_138 == (longlong *)0x0) goto LAB_23e77dbad;
              if ((plVar25 != (longlong *)0x0) &&
                 (lVar20 = *plVar25, *plVar25 = lVar20 + -1, lVar20 + -1 == 0)) {
                (**(code **)(plVar25[1] + 0x30))(plVar25);
              }
              plVar19 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8ae0);
              plVar23 = local_108;
              if (plVar19 == (longlong *)0x0) {
                auVar26 = *(undefined1 (*) [8])(param_1 + 0x60);
                uVar27 = 0x644;
                pcVar13 = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                pcVar28 = _Py_NoneStruct_exref;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                pcVar12 = *(code **)(param_1 + 0x68);
                goto LAB_23e77cdb0;
              }
              cVar5 = FUN_23a39bc50();
              *plVar19 = *plVar19 + -1;
              if (*plVar19 == 0) {
                (**(code **)(plVar19[1] + 0x30))();
              }
              local_118 = local_130;
              if (cVar5 == '\0') {
                auVar26 = *(undefined1 (*) [8])(param_1 + 0x60);
                uVar27 = 0x644;
                pcVar13 = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                pcVar28 = _Py_NoneStruct_exref;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                pcVar12 = *(code **)(param_1 + 0x68);
                goto LAB_23e77cdb0;
              }
              goto LAB_23e77c56c;
            }
            local_130 = (longlong *)0x0;
LAB_23e77d9da:
            pcVar13 = local_88[0];
            pcVar12 = pcStack_90;
            auVar26 = local_98;
            _local_98 = (undefined1  [16])0x0;
            local_88[0] = (code *)0x0;
            *plVar22 = *plVar22 + -1;
            if (*plVar22 == 0) {
              FUN_23a334bc0(plVar22);
            }
            local_88[0] = (code *)0x0;
            _local_98 = (undefined1  [16])0x0;
            if ((local_108 != (longlong *)0x0) && (*local_108 = *local_108 + -1, *local_108 == 0)) {
              FUN_23a334bc0(local_108);
            }
            if ((local_130 != (longlong *)0x0) &&
               (lVar20 = *local_130, *local_130 = lVar20 + -1, lVar20 + -1 == 0)) {
              FUN_23a334bc0();
            }
            local_130 = local_118;
            goto LAB_23e77da99;
          }
          plVar7 = (longlong *)0x0;
          do {
            lVar20 = plVar17[1];
            if (*(code **)(lVar20 + 0xe0) == (code *)0x0) {
              plVar23 = (longlong *)0x0;
              local_138 = (longlong *)0x0;
              local_118 = (longlong *)0x0;
              goto LAB_23e77c5e2;
            }
            plVar18 = (longlong *)(**(code **)(lVar20 + 0xe0))(plVar17);
            if (plVar18 == (longlong *)0x0) {
              plVar23 = (longlong *)0x0;
              local_138 = (longlong *)0x0;
              local_118 = (longlong *)0x0;
              goto LAB_23e77c607;
            }
            if ((plVar19 != (longlong *)0x0) && (*plVar19 = *plVar19 + -1, *plVar19 == 0)) {
              (**(code **)(plVar19[1] + 0x30))(plVar19);
            }
            *plVar18 = *plVar18 + 1;
            if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
              (**(code **)(plVar7[1] + 0x30))(plVar7);
            }
            plVar23 = (longlong *)FUN_23e8bc2f0(plVar18,DAT_23eed9778);
            if (plVar23 == (longlong *)0x0) {
              local_138 = (longlong *)0x0;
              local_118 = (longlong *)0x0;
              plVar23 = (longlong *)0x0;
              goto LAB_23e77d6af;
            }
            *(undefined4 *)(plVar2 + 5) = 0x63f;
            plVar7 = (longlong *)FUN_23e91a870(param_1,plVar23);
            *plVar23 = *plVar23 + -1;
            if (*plVar23 == 0) {
              (**(code **)(plVar23[1] + 0x30))(plVar23);
            }
            lVar20 = *plVar18;
            if (plVar7 == (longlong *)0x0) {
              plVar23 = (longlong *)0x0;
              local_138 = (longlong *)0x0;
              local_118 = (longlong *)0x0;
              goto LAB_23e77d6af;
            }
            *plVar18 = lVar20 + -1;
            if (lVar20 + -1 == 0) {
              (**(code **)(plVar18[1] + 0x30))(plVar18);
            }
            iVar6 = FUN_23a35f020(plVar7);
            if (iVar6 == -1) {
LAB_23e77e3be:
              plVar23 = (longlong *)0x0;
              local_138 = (longlong *)0x0;
              local_118 = (longlong *)0x0;
              goto LAB_23e77d860;
            }
            if (iVar6 != 0) {
              iVar6 = PySequence_Contains(plVar7,DAT_23eed9780);
              if (iVar6 == -1) goto LAB_23e77e3be;
              if (iVar6 == 1) {
                plVar23 = (longlong *)FUN_23e8bc2f0(plVar7,DAT_23ed6d020);
                if (plVar23 == (longlong *)0x0) {
                  local_138 = (longlong *)0x0;
                  local_118 = (longlong *)0x0;
                  plVar23 = (longlong *)0x0;
                  goto LAB_23e77dce3;
                }
                *(undefined4 *)(plVar2 + 5) = 0x641;
                plVar19 = (longlong *)FUN_23e9557e0(param_1,plVar23,DAT_23eed9788);
                *plVar23 = *plVar23 + -1;
                if (*plVar23 == 0) {
                  (**(code **)(plVar23[1] + 0x30))();
                }
                if (plVar19 == (longlong *)0x0) {
                  local_138 = (longlong *)0x0;
                  local_118 = (longlong *)0x0;
                  plVar23 = (longlong *)0x0;
                  goto LAB_23e77e20b;
                }
                plVar22 = (longlong *)FUN_23a388310(plVar19);
                *plVar19 = *plVar19 + -1;
                if (*plVar19 == 0) {
                  (**(code **)(plVar19[1] + 0x30))(plVar19);
                }
                if (plVar22 == (longlong *)0x0) {
                  plVar23 = (longlong *)0x0;
                  local_138 = (longlong *)0x0;
                  local_118 = (longlong *)0x0;
                  goto LAB_23e77dce3;
                }
                local_108 = (longlong *)(**(code **)(plVar22[1] + 0xe0))(plVar22);
                if ((local_108 == (longlong *)0x0) &&
                   (local_108 = (longlong *)FUN_23a3c1b70(param_1,local_98,0),
                   local_108 == (longlong *)0x0)) {
                  plVar23 = (longlong *)0x0;
                  local_138 = (longlong *)0x0;
                  local_118 = (longlong *)0x0;
                  local_130 = (longlong *)0x0;
                  goto LAB_23e77d9da;
                }
                local_130 = (longlong *)(**(code **)(plVar22[1] + 0xe0))(plVar22);
                if ((local_130 != (longlong *)0x0) ||
                   (local_130 = (longlong *)FUN_23a3c1b70(param_1,local_98,1,2),
                   local_130 != (longlong *)0x0)) {
                  cVar5 = FUN_23a3884a0(param_1,local_98);
                  lVar20 = *plVar22;
                  if (cVar5 != '\0') {
                    *plVar22 = lVar20 + -1;
                    if (lVar20 + -1 == 0) {
                      (**(code **)(plVar22[1] + 0x30))(plVar22);
                    }
                    if (*local_108 == 0) {
                      (**(code **)(local_108[1] + 0x30))(local_108);
                    }
                    if (*local_130 == 0) {
                      (**(code **)(local_130[1] + 0x30))();
                    }
                    plVar25 = (longlong *)FUN_23e8bc2f0(local_108,DAT_23eed9790);
                    if (plVar25 == (longlong *)0x0) goto LAB_23e77dbad;
                    *(undefined4 *)(plVar2 + 5) = 0x643;
                    local_138 = (longlong *)FUN_23e9557e0(param_1,plVar25);
                    lVar20 = *plVar25;
                    *plVar25 = lVar20 + -1;
                    if (lVar20 + -1 == 0) {
                      (**(code **)(plVar25[1] + 0x30))(plVar25);
                    }
                    if (local_138 == (longlong *)0x0) {
                      local_138 = (longlong *)0x0;
                      plVar25 = local_138;
                      goto LAB_23e77dbad;
                    }
                    FUN_23e8ba2b0(local_98,DAT_23eed8d30);
                    pcVar28 = _Py_NoneStruct_exref;
                    if ((local_98 != (undefined1  [8])_Py_NoneStruct_exref) &&
                       (local_98 != (undefined1  [8])0x0)) {
                      FUN_23e91b1b0(param_1,local_98,local_98 + 8,local_88);
                    }
                    FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),pcStack_90);
                    uVar27 = 0x644;
                    pcVar13 = local_88[0];
                    plVar23 = local_108;
                    auVar26 = local_98;
                    pcVar12 = pcStack_90;
                    goto LAB_23e77cdb0;
                  }
                }
                plVar23 = (longlong *)0x0;
                local_138 = (longlong *)0x0;
                local_118 = (longlong *)0x0;
                goto LAB_23e77d9da;
              }
            }
            lVar20 = *(longlong *)(param_1 + 0x10);
            if ((((*(int *)(*(longlong *)(lVar20 + 0x28) + 0x160) != 0) ||
                 (*(int *)(lVar20 + 0x78) != 0)) && (iVar6 = Py_MakePendingCalls(), iVar6 < 0)) &&
               (*(longlong *)(param_1 + 0x60) != 0)) {
              local_108 = (longlong *)0x0;
              local_138 = (longlong *)0x0;
              local_118 = (longlong *)0x0;
              goto LAB_23e77cd65;
            }
            if (*(int *)(lVar20 + 0x68) != 0) {
              PyEval_SaveThread();
              PyEval_AcquireThread(param_1);
            }
            plVar23 = *(longlong **)(param_1 + 0x90);
            plVar19 = plVar18;
          } while (plVar23 == (longlong *)0x0);
          local_108 = (longlong *)0x0;
          local_138 = (longlong *)0x0;
          local_118 = (longlong *)0x0;
LAB_23e77cce5:
          plVar19 = *(longlong **)(param_1 + 0x60);
          plVar22 = *(longlong **)(param_1 + 0x68);
          *(undefined8 *)(param_1 + 0x90) = 0;
          plVar25 = *(longlong **)(param_1 + 0x70);
          *(longlong **)(param_1 + 0x60) = plVar23;
          *plVar23 = *plVar23 + 1;
          *(undefined8 *)(param_1 + 0x68) = 0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          if ((plVar19 != (longlong *)0x0) && (*plVar19 = *plVar19 + -1, *plVar19 == 0)) {
            (**(code **)(plVar19[1] + 0x30))();
          }
          if ((plVar22 != (longlong *)0x0) && (*plVar22 = *plVar22 + -1, *plVar22 == 0)) {
            (**(code **)(plVar22[1] + 0x30))(plVar22);
          }
          if ((plVar25 != (longlong *)0x0) && (*plVar25 = *plVar25 + -1, *plVar25 == 0)) {
            (**(code **)(plVar25[1] + 0x30))(plVar25);
          }
LAB_23e77cd65:
          pcVar28 = _Py_NoneStruct_exref;
          auVar26 = *(undefined1 (*) [8])(param_1 + 0x60);
          local_130 = local_118;
          pcVar13 = *(code **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar27 = 0x63e;
          plVar23 = local_108;
          pcVar12 = *(code **)(param_1 + 0x68);
          goto LAB_23e77cdb0;
        }
        auVar26 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcVar13 = *(code **)(param_1 + 0x70);
        plVar23 = (longlong *)0x0;
        plVar7 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar28 = _Py_NoneStruct_exref;
        uVar27 = 0x63e;
        local_138 = (longlong *)0x0;
        local_130 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar12 = *(code **)(param_1 + 0x68);
        goto LAB_23e77ce36;
      }
      local_128 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      auVar26 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcVar13 = *(code **)(param_1 + 0x68);
      local_98 = (undefined1  [8])0x0;
      pcStack_90 = (code *)0x0;
      lVar20 = *plVar14;
      local_88[0] = (code *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar14 = lVar20 + -1;
      if (lVar20 + -1 != 0) {
        lVar20 = *plVar15;
        *plVar15 = lVar20 + -1;
        if (lVar20 + -1 == 0) {
          (**(code **)(plVar15[1] + 0x30))();
        }
        goto LAB_23e77d4a0;
      }
      plVar23 = (longlong *)0x0;
      plVar7 = (longlong *)0x0;
      local_140 = (longlong *)0x0;
      local_138 = (longlong *)0x0;
      iVar6 = 0x63d;
      local_130 = (longlong *)0x0;
      pcVar28 = _Py_NoneStruct_exref;
      goto LAB_23e77d323;
    }
    local_128 = *(code **)(param_1 + 0x70);
    auVar26 = *(undefined1 (*) [8])(param_1 + 0x60);
    pcVar13 = *(code **)(param_1 + 0x68);
    plVar23 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar7 = (longlong *)0x0;
    iVar6 = 0x63d;
    *(undefined8 *)(param_1 + 0x70) = 0;
    local_138 = (longlong *)0x0;
    local_130 = (longlong *)0x0;
    local_140 = (longlong *)0x0;
    goto LAB_23e77d29d;
  }
  iVar6 = *(int *)(lVar20 + 0xc);
  if (*(int *)(lVar20 + 0xc) == 0) {
    *(int *)(lVar20 + 0xc) = DAT_23ec1545c;
    iVar6 = DAT_23ec1545c;
    DAT_23ec1545c = DAT_23ec1545c + 1;
  }
  if (DAT_23ec15420 != iVar6) {
    DAT_23ec15420 = iVar6;
    DAT_23eedad28 = FUN_23e8cbd60(lVar20);
  }
  if (-1 < DAT_23eedad28) {
    lVar9 = lVar20 + 0x20 + (1L << (*(byte *)(lVar20 + 9) & 0x3f));
    if (*(longlong *)(lVar9 + 8 + DAT_23eedad28 * 0x10) != 0) goto LAB_23e77af5d;
    DAT_23eedad28 = FUN_23e8cbd60(lVar20);
    if (-1 < DAT_23eedad28) {
      lVar20 = *(longlong *)(lVar9 + 8 + DAT_23eedad28 * 0x10);
      goto LAB_23e77c118;
    }
  }
LAB_23e77b1c9:
  plVar7 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eed9758);
  if ((plVar7 != (longlong *)0x0) && (*plVar7 != 0)) goto LAB_23e77af5d;
  FUN_23e915740(param_1,local_98);
LAB_23e77b269:
  plVar23 = (longlong *)0x0;
  plVar7 = (longlong *)0x0;
  plVar8 = (longlong *)0x0;
  local_138 = (longlong *)0x0;
  iVar6 = 0x63b;
  local_130 = (longlong *)0x0;
  local_140 = (longlong *)0x0;
  pcVar28 = _Py_NoneStruct_exref;
  goto LAB_23e77b29a;
LAB_23e77d6af:
  auVar26 = *(undefined1 (*) [8])(param_1 + 0x60);
  pcVar13 = *(code **)(param_1 + 0x70);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  uVar27 = 0x63f;
  *(undefined8 *)(param_1 + 0x70) = 0;
  local_130 = local_118;
  pcVar28 = _Py_NoneStruct_exref;
  plVar7 = plVar18;
  pcVar12 = *(code **)(param_1 + 0x68);
  goto LAB_23e77cdb0;
LAB_23e77d860:
  auVar26 = *(undefined1 (*) [8])(param_1 + 0x60);
  pcVar13 = *(code **)(param_1 + 0x70);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  pcVar28 = _Py_NoneStruct_exref;
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar27 = 0x640;
  local_130 = local_118;
  pcVar12 = *(code **)(param_1 + 0x68);
  goto LAB_23e77cdb0;
LAB_23e77e20b:
  auVar26 = *(undefined1 (*) [8])(param_1 + 0x60);
  pcVar12 = *(code **)(param_1 + 0x68);
  pcVar13 = *(code **)(param_1 + 0x70);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  *(undefined8 *)(param_1 + 0x70) = 0;
  local_130 = local_118;
  goto LAB_23e77da99;
LAB_23e77dce3:
  auVar26 = *(undefined1 (*) [8])(param_1 + 0x60);
  pcVar12 = *(code **)(param_1 + 0x68);
  local_130 = local_118;
  pcVar13 = *(code **)(param_1 + 0x70);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  *(undefined8 *)(param_1 + 0x70) = 0;
LAB_23e77da99:
  uVar27 = 0x641;
  pcVar28 = _Py_NoneStruct_exref;
  goto LAB_23e77cdb0;
LAB_23e77c5e2:
  PyErr_Format(*(undefined8 *)PyExc_TypeError_exref,"\'%s\' object is not an iterator",
               *(undefined8 *)(lVar20 + 0x18));
LAB_23e77c607:
  plVar18 = plVar19;
  cVar5 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
  if (cVar5 == '\0') {
    pcVar13 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcVar28 = _Py_NoneStruct_exref;
    local_130 = local_118;
    uVar27 = 0x63e;
    local_88[0] = (code *)0x0;
    auVar26 = *(undefined1 (*) [8])(param_1 + 0x60);
    pcVar12 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    _local_98 = (undefined1  [16])0x0;
    if (plVar18 != (longlong *)0x0) goto LAB_23e77cdb0;
    goto LAB_23e77cde0;
  }
  if ((plVar18 != (longlong *)0x0) && (*plVar18 = *plVar18 + -1, *plVar18 == 0)) {
    FUN_23a334bc0(plVar18);
  }
  lVar20 = *plVar17;
  *plVar17 = lVar20 + -1;
  if (lVar20 + -1 == 0) {
    FUN_23a334bc0(plVar17);
  }
  *(undefined4 *)(plVar2 + 5) = 0x63d;
  plVar17 = (longlong *)FUN_23e957a30(param_1,plVar16);
  if (plVar17 == (longlong *)0x0) {
    local_128 = *(code **)(param_1 + 0x70);
    auVar26 = *(undefined1 (*) [8])(param_1 + 0x60);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    pcVar28 = _Py_NoneStruct_exref;
    iVar6 = 0x63d;
    *(undefined8 *)(param_1 + 0x70) = 0;
    local_130 = local_118;
    pcVar13 = *(code **)(param_1 + 0x68);
    goto LAB_23e77d216;
  }
  *plVar17 = *plVar17 + -1;
  if (*plVar17 == 0) {
    FUN_23a334bc0();
  }
  local_130 = local_118;
  pcVar28 = _Py_NoneStruct_exref;
  goto LAB_23e77c6ab;
LAB_23e77dbad:
  local_138 = plVar25;
  auVar26 = *(undefined1 (*) [8])(param_1 + 0x60);
  pcVar13 = *(code **)(param_1 + 0x70);
  uVar27 = 0x643;
  *(undefined8 *)(param_1 + 0x70) = 0;
  pcVar28 = _Py_NoneStruct_exref;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar23 = local_108;
  pcVar12 = *(code **)(param_1 + 0x68);
LAB_23e77cdb0:
  local_88[0] = (code *)0x0;
  _local_98 = (undefined1  [16])0x0;
  *plVar18 = *plVar18 + -1;
  if (*plVar18 == 0) {
    (**(code **)(plVar18[1] + 0x30))(plVar18);
  }
LAB_23e77cde0:
  lVar20 = *plVar17;
  *plVar17 = lVar20 + -1;
  if (lVar20 + -1 == 0) {
    (**(code **)(plVar17[1] + 0x30))(plVar17);
  }
LAB_23e77ce36:
  pcStack_90 = pcVar12;
  local_98 = auVar26;
  local_88[0] = pcVar13;
  pcVar13 = local_88[0];
  local_b8._8_8_ = pcStack_90;
  local_b8._0_8_ = local_98;
  local_88[0] = (code *)0x0;
  local_98 = (undefined1  [8])0x0;
  pcStack_90 = (code *)0x0;
  local_a8[0] = pcVar13;
  plVar17 = *(longlong **)(param_1 + 0x138);
  if (plVar17 != (longlong *)0x0) {
    *plVar17 = *plVar17 + 1;
  }
  pcVar12 = DAT_23ed6a4f8;
  if (pcVar13 == (code *)0x0) {
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar12 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar13 = *(code **)DAT_23ed6a4f8;
      *(undefined8 *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar13;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar13 = _PyRuntime_exref;
    *(longlong *)(pcVar12 + 0x10) = 0;
    *(longlong **)(pcVar12 + 0x18) = plVar2;
    *plVar2 = *plVar2 + 1;
    lVar20 = *(longlong *)(pcVar13 + 0x1f8);
    *(undefined4 *)(pcVar12 + 0x24) = uVar27;
    lVar20 = *(longlong *)(lVar20 + 0x10);
    *(undefined4 *)(pcVar12 + 0x20) = 0xffffffff;
    lVar20 = *(longlong *)(lVar20 + 0x2e8);
    lVar9 = *(longlong *)(pcVar12 + -8);
    plVar19 = *(longlong **)(lVar20 + 8);
    *plVar19 = (longlong)(pcVar12 + -0x10);
    *(longlong *)(pcVar12 + -0x10) = lVar20;
    *(ulonglong *)(pcVar12 + -8) = (ulonglong)((uint)lVar9 & 3) | (ulonglong)plVar19;
    *(code **)(lVar20 + 8) = pcVar12 + -0x10;
    if ((local_a8[0] != (code *)0x0) &&
       (*(longlong *)local_a8[0] = *(longlong *)local_a8[0] + -1, *(longlong *)local_a8[0] == 0)) {
      FUN_23a334bc0(local_a8[0]);
    }
  }
  else {
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar12 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar11 = *(code **)DAT_23ed6a4f8;
      *(undefined8 *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar11;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar11 = _PyRuntime_exref;
    *(longlong **)(pcVar12 + 0x18) = plVar2;
    *plVar2 = *plVar2 + 1;
    lVar20 = *(longlong *)(pcVar11 + 0x1f8);
    *(undefined4 *)(pcVar12 + 0x24) = uVar27;
    *(undefined4 *)(pcVar12 + 0x20) = 0xffffffff;
    lVar20 = *(longlong *)(*(longlong *)(lVar20 + 0x10) + 0x2e8);
    lVar9 = *(longlong *)(pcVar12 + -8);
    plVar19 = *(longlong **)(lVar20 + 8);
    *plVar19 = (longlong)(pcVar12 + -0x10);
    *(longlong *)(pcVar12 + -0x10) = lVar20;
    *(ulonglong *)(pcVar12 + -8) = (ulonglong)((uint)lVar9 & 3) | (ulonglong)plVar19;
    *(code **)(lVar20 + 8) = pcVar12 + -0x10;
    *(code **)(pcVar12 + 0x10) = pcVar13;
    *(longlong *)pcVar13 = *(longlong *)pcVar13 + 1;
    if ((local_a8[0] != (code *)0x0) &&
       (*(longlong *)local_a8[0] = *(longlong *)local_a8[0] + -1, *(longlong *)local_a8[0] == 0)) {
      (**(code **)(*(longlong *)(local_a8[0] + 8) + 0x30))();
    }
  }
  local_a8[0] = pcVar12;
  if (((code *)local_b8._0_8_ != pcVar28) && ((code *)local_b8._0_8_ != (code *)0x0)) {
    FUN_23e91b1b0(param_1,local_b8,local_b8 + 8,local_a8);
  }
  plVar19 = *(longlong **)(local_b8._8_8_ + 0x28);
  if (local_a8[0] == pcVar28) {
    pcVar13 = (code *)0x0;
  }
  else {
    pcVar13 = local_a8[0];
    if (local_a8[0] != (code *)0x0) {
      *(longlong *)local_a8[0] = *(longlong *)local_a8[0] + 1;
    }
  }
  *(code **)(local_b8._8_8_ + 0x28) = pcVar13;
  if ((plVar19 != (longlong *)0x0) && (*plVar19 = *plVar19 + -1, *plVar19 == 0)) {
    (**(code **)(plVar19[1] + 0x30))();
  }
  plVar19 = *(longlong **)(param_1 + 0x138);
  *(undefined8 *)(param_1 + 0x138) = local_b8._8_8_;
  if ((plVar19 != (longlong *)0x0) && (*plVar19 = *plVar19 + -1, *plVar19 == 0)) {
    (**(code **)(plVar19[1] + 0x30))();
  }
  *(longlong *)local_b8._0_8_ = *(longlong *)local_b8._0_8_ + -1;
  if (*(longlong *)local_b8._0_8_ == 0) {
    (**(code **)(*(longlong *)(local_b8._0_8_ + 8) + 0x30))();
  }
  if ((local_a8[0] != (code *)0x0) &&
     (*(longlong *)local_a8[0] = *(longlong *)local_a8[0] + -1, *(longlong *)local_a8[0] == 0)) {
    (**(code **)(*(longlong *)(local_a8[0] + 8) + 0x30))();
  }
  local_a8[0] = (code *)0x0;
  local_b8 = (undefined1  [16])0x0;
  iVar6 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                        *(undefined8 *)PyExc_BaseException_exref);
  if (iVar6 == 0) {
    pcVar13 = *(code **)(param_1 + 0x138);
    pcStack_90 = pcVar13;
    if ((pcVar13 == pcVar28) || (pcVar13 == (code *)0x0)) {
      pcVar11 = *(code **)PyExc_RuntimeError_exref;
      pcVar12 = (code *)PyUnicode_FromString("No active exception to reraise");
      iVar6 = 0x63d;
      *(longlong *)pcVar11 = *(longlong *)pcVar11 + 1;
LAB_23e77d91c:
      pcVar13 = *(code **)(param_1 + 0x138);
      pcVar24 = (code *)0x0;
      bVar4 = true;
      goto LAB_23e77d739;
    }
    pcVar11 = *(code **)(pcVar13 + 8);
    pcVar24 = *(code **)(pcVar13 + 0x28);
    *(longlong *)pcVar13 = *(longlong *)pcVar13 + 1;
    *(longlong *)pcVar11 = *(longlong *)pcVar11 + 1;
    iVar6 = 0;
    pcVar12 = pcVar13;
    if (pcVar24 == (code *)0x0) goto LAB_23e77d91c;
    *(longlong *)pcVar24 = *(longlong *)pcVar24 + 1;
    if (*(longlong **)(pcVar24 + 0x18) == plVar2) {
      *(undefined4 *)(plVar2 + 5) = *(undefined4 *)(pcVar24 + 0x24);
    }
    bVar4 = true;
LAB_23e77d136:
    iVar6 = 0;
    *(longlong **)(param_1 + 0x138) = plVar17;
    pcVar12 = pcVar13;
LAB_23e77d160:
    local_88[0] = (code *)0x0;
    _local_98 = (undefined1  [16])0x0;
    *(longlong *)pcVar13 = *(longlong *)pcVar13 + -1;
    if (*(longlong *)pcVar13 == 0) {
      (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))();
    }
LAB_23e77d1a8:
    local_88[0] = (code *)0x0;
    _local_98 = (undefined1  [16])0x0;
    local_78 = pcVar11;
    pcStack_70 = pcVar12;
    local_68 = pcVar24;
    if (bVar4) {
      *(undefined4 *)(plVar2 + 5) = 0x63d;
      plVar17 = (longlong *)FUN_23e957a30(param_1,plVar16);
      if (plVar17 != (longlong *)0x0) {
        *plVar17 = *plVar17 + -1;
        if (*plVar17 == 0) {
          FUN_23a334bc0();
        }
        goto LAB_23e77d1f3;
      }
      local_88[0] = *(code **)(param_1 + 0x70);
      local_98 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_90 = *(code **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      FUN_23a35d6b0();
      iVar6 = 0x63d;
      local_128 = local_88[0];
      auVar26 = local_98;
      pcVar13 = pcStack_90;
    }
    else {
LAB_23e77d1f3:
      local_128 = local_68;
      auVar26 = (undefined1  [8])local_78;
      pcVar13 = pcStack_70;
    }
LAB_23e77d216:
    local_88[0] = (code *)0x0;
    local_98 = (undefined1  [8])0x0;
    pcStack_90 = (code *)0x0;
    lVar20 = *plVar14;
    *plVar14 = lVar20 + -1;
    if (lVar20 + -1 == 0) {
LAB_23e77d323:
      pcStack_90 = (code *)0x0;
      local_98 = (undefined1  [8])0x0;
      local_88[0] = (code *)0x0;
      (**(code **)(plVar14[1] + 0x30))();
      lVar20 = *plVar15;
      *plVar15 = lVar20 + -1;
      if (lVar20 + -1 == 0) goto LAB_23e77d35d;
LAB_23e77d374:
      if (plVar16 != (longlong *)0x0) goto LAB_23e77d270;
    }
    else {
      lVar20 = *plVar15;
      *plVar15 = lVar20 + -1;
      if (lVar20 + -1 == 0) {
LAB_23e77d35d:
        (**(code **)(plVar15[1] + 0x30))();
        goto LAB_23e77d374;
      }
LAB_23e77d270:
      lVar20 = *plVar16;
      *plVar16 = lVar20 + -1;
      if (lVar20 + -1 == 0) {
        (**(code **)(plVar16[1] + 0x30))();
      }
    }
LAB_23e77d29d:
    local_88[0] = local_128;
    local_98 = auVar26;
    pcStack_90 = pcVar13;
  }
  else {
    pcStack_70 = *(code **)(param_1 + 0x138);
    local_78 = *(code **)(pcStack_70 + 8);
    local_68 = *(code **)(pcStack_70 + 0x28);
    *(undefined4 *)(plVar2 + 5) = 0x63d;
    if (local_68 == (code *)0x0) {
      local_68 = pcVar28;
    }
    plVar19 = (longlong *)FUN_23e956150(param_1,plVar16);
    if (plVar19 == (longlong *)0x0) {
      pcVar24 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      iVar6 = 0x63d;
      bVar4 = false;
      pcVar13 = *(code **)(param_1 + 0x138);
      pcVar11 = *(code **)(param_1 + 0x60);
      pcVar12 = *(code **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e77d739:
      *(longlong **)(param_1 + 0x138) = plVar17;
      if (pcVar13 != (code *)0x0) goto LAB_23e77d160;
      goto LAB_23e77d1a8;
    }
    iVar6 = FUN_23a35f020();
    *plVar19 = *plVar19 + -1;
    if (*plVar19 == 0) {
      (**(code **)(plVar19[1] + 0x30))();
    }
    if (iVar6 == -1) {
      pcVar11 = *(code **)(param_1 + 0x60);
      pcVar12 = *(code **)(param_1 + 0x68);
      pcVar24 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      iVar6 = 0x63d;
      bVar4 = false;
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcVar13 = *(code **)(param_1 + 0x138);
      goto LAB_23e77d739;
    }
    if (iVar6 == 0) {
      pcVar12 = *(code **)(param_1 + 0x138);
      pcStack_90 = pcVar12;
      if ((pcVar12 == pcVar28) || (pcVar12 == (code *)0x0)) {
        pcVar11 = *(code **)PyExc_RuntimeError_exref;
        pcVar12 = (code *)PyUnicode_FromString("No active exception to reraise");
        iVar6 = 0x63d;
        *(longlong *)pcVar11 = *(longlong *)pcVar11 + 1;
      }
      else {
        pcVar11 = *(code **)(pcVar12 + 8);
        pcVar24 = *(code **)(pcVar12 + 0x28);
        *(longlong *)pcVar12 = *(longlong *)pcVar12 + 1;
        *(longlong *)pcVar11 = *(longlong *)pcVar11 + 1;
        if (pcVar24 != (code *)0x0) {
          *(longlong *)pcVar24 = *(longlong *)pcVar24 + 1;
          if (*(longlong **)(pcVar24 + 0x18) == plVar2) {
            *(undefined4 *)(plVar2 + 5) = *(undefined4 *)(pcVar24 + 0x24);
          }
          bVar4 = false;
          pcVar13 = pcVar12;
          goto LAB_23e77d136;
        }
        iVar6 = 0;
      }
      pcVar13 = *(code **)(param_1 + 0x138);
      pcVar24 = (code *)0x0;
      bVar4 = false;
      goto LAB_23e77d739;
    }
    plVar19 = *(longlong **)(param_1 + 0x138);
    *(longlong **)(param_1 + 0x138) = plVar17;
    if ((plVar19 != (longlong *)0x0) && (*plVar19 = *plVar19 + -1, *plVar19 == 0)) {
      (**(code **)(plVar19[1] + 0x30))();
    }
LAB_23e77c6ab:
    lVar20 = *plVar14;
    *plVar14 = lVar20 + -1;
    if (lVar20 + -1 == 0) {
      FUN_23a334bc0(plVar14);
    }
    lVar20 = *plVar15;
    *plVar15 = lVar20 + -1;
    if (lVar20 + -1 == 0) {
      FUN_23a334bc0(plVar15);
    }
    lVar20 = *plVar16;
    *plVar16 = lVar20 + -1;
    if (lVar20 + -1 == 0) {
      FUN_23a334bc0(plVar16);
    }
    if (plVar1 == (longlong *)0x0) {
      FUN_23e8ba2b0(local_98,DAT_23eed8d30);
      if ((local_98 != (undefined1  [8])pcVar28) && (local_98 != (undefined1  [8])0x0)) {
        FUN_23e91b1b0(param_1,local_98,local_98 + 8,local_88);
      }
      FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),pcStack_90);
    }
    else {
      plVar15 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8b40);
      plVar14 = DAT_23eed97a0;
      if (plVar15 == (longlong *)0x0) {
LAB_23e77dbed:
        local_98 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_90 = *(code **)(param_1 + 0x68);
        local_88[0] = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      }
      else {
        lVar20 = *(longlong *)(param_1 + 0x10);
        plVar16 = *(longlong **)(lVar20 + 0xe28);
        if (plVar16 == (longlong *)0x0) {
          plVar16 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
        }
        else {
          lVar9 = plVar16[3];
          *(int *)(lVar20 + 0xec0) = *(int *)(lVar20 + 0xec0) + -1;
          *(longlong *)(lVar20 + 0xe28) = lVar9;
          *plVar16 = 1;
        }
        pcVar13 = _PyRuntime_exref;
        *(undefined1 (*) [16])(plVar16 + 4) = (undefined1  [16])0x0;
        lVar20 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar13 + 0x1f8) + 0x10) + 0x2e8);
        lVar9 = plVar16[-1];
        puVar3 = *(undefined8 **)(lVar20 + 8);
        *puVar3 = plVar16 + -2;
        plVar16[-2] = lVar20;
        plVar16[-1] = (ulonglong)((uint)lVar9 & 3) | (ulonglong)puVar3;
        *(longlong **)(lVar20 + 8) = plVar16 + -2;
        uVar10 = DAT_23eed8ae0;
        *plVar14 = *plVar14 + 1;
        plVar16[3] = (longlong)plVar14;
        plVar14 = (longlong *)FUN_23e8bc2f0(plVar1,uVar10);
        if (plVar14 == (longlong *)0x0) {
LAB_23e77d930:
          local_88[0] = *(code **)(param_1 + 0x70);
          local_98 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcStack_90 = *(code **)(param_1 + 0x68);
          *(undefined8 *)(param_1 + 0x70) = 0;
          lVar20 = *plVar15;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar15 = lVar20 + -1;
          if (lVar20 + -1 == 0) {
            FUN_23a334bc0();
          }
          *plVar16 = *plVar16 + -1;
          lVar20 = *plVar16;
        }
        else {
          plVar17 = (longlong *)FUN_23e8bd600(param_1,plVar14);
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            FUN_23a334bc0();
          }
          if (plVar17 == (longlong *)0x0) goto LAB_23e77d930;
          lVar20 = FUN_23e94f9d0();
          *plVar17 = *plVar17 + -1;
          if (*plVar17 == 0) {
            FUN_23a334bc0();
          }
          if (lVar20 == 0) goto LAB_23e77d930;
          plVar16[4] = lVar20;
          plVar14 = DAT_23eed97a8;
          *DAT_23eed97a8 = *DAT_23eed97a8 + 1;
          plVar16[5] = (longlong)plVar14;
          plVar14 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar16);
          *plVar16 = *plVar16 + -1;
          if (*plVar16 == 0) {
            FUN_23a334bc0();
          }
          if (plVar14 != (longlong *)0x0) {
            *(undefined4 *)(plVar2 + 5) = 0x645;
            plVar16 = (longlong *)FUN_23e914090(param_1,plVar15);
            lVar20 = *plVar15;
            *plVar15 = lVar20 + -1;
            if (lVar20 + -1 == 0) {
              FUN_23a334bc0();
            }
            *plVar14 = *plVar14 + -1;
            if (*plVar14 == 0) {
              FUN_23a334bc0();
            }
            if (plVar16 != (longlong *)0x0) {
              *plVar16 = *plVar16 + -1;
              if (*plVar16 == 0) {
                FUN_23a334bc0(plVar16);
              }
LAB_23e77b090:
              lVar20 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
              plVar2 = *(longlong **)(lVar20 + 0x28);
              plVar14 = (longlong *)plVar2[2];
              *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar20 + 0x30);
              *(undefined4 *)(plVar2 + 8) = 0xffffffff;
              if (plVar14 != (longlong *)0x0) {
                plVar2[2] = 0;
                *plVar14 = *plVar14 + -1;
                if (*plVar14 == 0) {
                  (**(code **)(plVar14[1] + 0x30))();
                }
              }
              *plVar2 = *plVar2 + -1;
              if (*plVar2 == 0) {
                (**(code **)(plVar2[1] + 0x30))(plVar2);
              }
              *(longlong *)pcVar28 = *(longlong *)pcVar28 + 1;
              plVar2[0xf] = 0;
              if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
                (**(code **)(plVar8[1] + 0x30))(plVar8);
              }
              if ((local_140 != (longlong *)0x0) &&
                 (lVar20 = *local_140, *local_140 = lVar20 + -1, lVar20 + -1 == 0)) {
                (**(code **)(local_140[1] + 0x30))(local_140);
              }
              if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
                (**(code **)(plVar7[1] + 0x30))(plVar7);
              }
              if ((plVar23 != (longlong *)0x0) && (*plVar23 = *plVar23 + -1, *plVar23 == 0)) {
                (**(code **)(plVar23[1] + 0x30))(plVar23);
              }
              if ((local_130 != (longlong *)0x0) &&
                 (lVar20 = *local_130, *local_130 = lVar20 + -1, lVar20 + -1 == 0)) {
                (**(code **)(local_130[1] + 0x30))(local_130);
              }
              if ((local_138 != (longlong *)0x0) &&
                 (lVar20 = *local_138, *local_138 = lVar20 + -1, lVar20 + -1 == 0)) {
                (**(code **)(local_138[1] + 0x30))(local_138);
              }
              *plVar1 = *plVar1 + -1;
              if (*plVar1 != 0) {
                return pcVar28;
              }
              (**(code **)(plVar1[1] + 0x30))(plVar1);
              return pcVar28;
            }
            goto LAB_23e77dbed;
          }
          local_88[0] = *(code **)(param_1 + 0x70);
          local_98 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcStack_90 = *(code **)(param_1 + 0x68);
          *(undefined8 *)(param_1 + 0x70) = 0;
          lVar20 = *plVar15 + -1;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar15 = lVar20;
        }
        if (lVar20 == 0) {
          FUN_23a334bc0();
        }
      }
    }
    iVar6 = 0x645;
  }
LAB_23e77b29a:
  pcVar13 = local_88[0];
  local_d8._8_8_ = pcStack_90;
  local_d8._0_8_ = local_98;
  local_88[0] = (code *)0x0;
  local_98 = (undefined1  [8])0x0;
  pcStack_90 = (code *)0x0;
  local_c8[0] = pcVar13;
  plVar14 = *(longlong **)(param_1 + 0x138);
  if (plVar14 != (longlong *)0x0) {
    *plVar14 = *plVar14 + 1;
  }
  pcVar12 = DAT_23ed6a4f8;
  if (pcVar13 == (code *)0x0) {
    if (iVar6 == 0) {
      iVar6 = (int)plVar2[5];
    }
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar12 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      pcVar13 = local_c8[0];
    }
    else {
      pcVar13 = *(code **)DAT_23ed6a4f8;
      *(undefined8 *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar13;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      pcVar13 = (code *)0x0;
    }
    pcVar11 = _PyRuntime_exref;
    *(longlong *)(pcVar12 + 0x10) = 0;
    *(longlong **)(pcVar12 + 0x18) = plVar2;
    *plVar2 = *plVar2 + 1;
    lVar20 = *(longlong *)(pcVar11 + 0x1f8);
    *(int *)(pcVar12 + 0x24) = iVar6;
    lVar20 = *(longlong *)(lVar20 + 0x10);
    *(undefined4 *)(pcVar12 + 0x20) = 0xffffffff;
    lVar20 = *(longlong *)(lVar20 + 0x2e8);
    lVar9 = *(longlong *)(pcVar12 + -8);
    plVar15 = *(longlong **)(lVar20 + 8);
    *plVar15 = (longlong)(pcVar12 + -0x10);
    *(longlong *)(pcVar12 + -0x10) = lVar20;
    *(ulonglong *)(pcVar12 + -8) = (ulonglong)((uint)lVar9 & 3) | (ulonglong)plVar15;
    *(code **)(lVar20 + 8) = pcVar12 + -0x10;
    pcVar11 = pcVar12;
    if ((pcVar13 != (code *)0x0) &&
       (*(longlong *)pcVar13 = *(longlong *)pcVar13 + -1, *(longlong *)pcVar13 == 0)) {
      (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))();
    }
  }
  else {
    pcVar11 = local_c8[0];
    if (iVar6 != 0) {
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar12 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar11 = *(code **)DAT_23ed6a4f8;
        *(undefined8 *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar11;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar11 = _PyRuntime_exref;
      *(longlong **)(pcVar12 + 0x18) = plVar2;
      *plVar2 = *plVar2 + 1;
      lVar20 = *(longlong *)(pcVar11 + 0x1f8);
      *(int *)(pcVar12 + 0x24) = iVar6;
      *(undefined4 *)(pcVar12 + 0x20) = 0xffffffff;
      lVar20 = *(longlong *)(*(longlong *)(lVar20 + 0x10) + 0x2e8);
      lVar9 = *(longlong *)(pcVar12 + -8);
      plVar15 = *(longlong **)(lVar20 + 8);
      *plVar15 = (longlong)(pcVar12 + -0x10);
      *(longlong *)(pcVar12 + -0x10) = lVar20;
      *(ulonglong *)(pcVar12 + -8) = (ulonglong)((uint)lVar9 & 3) | (ulonglong)plVar15;
      *(code **)(lVar20 + 8) = pcVar12 + -0x10;
      *(code **)(pcVar12 + 0x10) = pcVar13;
      *(longlong *)pcVar13 = *(longlong *)pcVar13 + 1;
      pcVar11 = pcVar12;
      if ((local_c8[0] != (code *)0x0) &&
         (*(longlong *)local_c8[0] = *(longlong *)local_c8[0] + -1, *(longlong *)local_c8[0] == 0))
      {
        (**(code **)(*(longlong *)(local_c8[0] + 8) + 0x30))();
      }
    }
  }
  local_c8[0] = pcVar11;
  if (((code *)local_d8._0_8_ != pcVar28) && ((code *)local_d8._0_8_ != (code *)0x0)) {
    FUN_23e91b1b0(param_1,local_d8,local_d8 + 8,local_c8);
  }
  plVar15 = *(longlong **)(local_d8._8_8_ + 0x28);
  if (local_c8[0] == pcVar28) {
    pcVar13 = (code *)0x0;
  }
  else {
    pcVar13 = local_c8[0];
    if (local_c8[0] != (code *)0x0) {
      *(longlong *)local_c8[0] = *(longlong *)local_c8[0] + 1;
    }
  }
  *(code **)(local_d8._8_8_ + 0x28) = pcVar13;
  if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
    (**(code **)(plVar15[1] + 0x30))();
  }
  plVar15 = *(longlong **)(param_1 + 0x138);
  *(undefined8 *)(param_1 + 0x138) = local_d8._8_8_;
  if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
    (**(code **)(plVar15[1] + 0x30))();
  }
  *(longlong *)local_d8._0_8_ = *(longlong *)local_d8._0_8_ + -1;
  if (*(longlong *)local_d8._0_8_ == 0) {
    (**(code **)(*(longlong *)(local_d8._0_8_ + 8) + 0x30))();
  }
  if ((local_c8[0] != (code *)0x0) &&
     (*(longlong *)local_c8[0] = *(longlong *)local_c8[0] + -1, *(longlong *)local_c8[0] == 0)) {
    (**(code **)(*(longlong *)(local_c8[0] + 8) + 0x30))();
  }
  pcVar13 = *(code **)(param_1 + 0x138);
  local_c8[0] = (code *)0x0;
  local_d8 = (undefined1  [16])0x0;
  pcVar12 = *(code **)PyExc_Exception_exref;
  pcVar11 = *(code **)(pcVar13 + 8);
  if ((*(uint *)(*(longlong *)(pcVar12 + 8) + 0xa8) & 0x4000000) == 0) {
    if ((-1 < (int)*(uint *)(*(longlong *)(pcVar12 + 8) + 0xa8)) ||
       (((byte)pcVar12[0xab] & 0x40) == 0)) {
LAB_23e77b800:
      plVar15 = *(longlong **)PyExc_TypeError_exref;
      uVar10 = PyUnicode_FromString
                         ("catching classes that do not inherit from BaseException is not allowed");
      plVar16 = *(longlong **)(param_1 + 0x60);
      plVar17 = *(longlong **)(param_1 + 0x70);
      plVar19 = *(longlong **)(param_1 + 0x68);
      *(longlong **)(param_1 + 0x60) = plVar15;
      *plVar15 = *plVar15 + 1;
      *(undefined8 *)(param_1 + 0x68) = uVar10;
      *(undefined8 *)(param_1 + 0x70) = 0;
      if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
        (**(code **)(plVar16[1] + 0x30))();
      }
      if ((plVar19 != (longlong *)0x0) && (*plVar19 = *plVar19 + -1, *plVar19 == 0)) {
        (**(code **)(plVar19[1] + 0x30))(plVar19);
      }
      if ((plVar17 == (longlong *)0x0) || (*plVar17 = *plVar17 + -1, *plVar17 != 0)) {
LAB_23e77b871:
        pcVar24 = *(code **)(param_1 + 0x138);
      }
      else {
        (**(code **)(plVar17[1] + 0x30))(plVar17);
        pcVar24 = *(code **)(param_1 + 0x138);
      }
LAB_23e77b878:
      *(longlong *)pcVar24 = *(longlong *)pcVar24 + 1;
      if (plVar1 == (longlong *)0x0) {
        pcStack_90 = (code *)PyUnicode_FromFormat
                                       ("cannot access local variable \'%U\' where it is not associated with a value"
                                        ,DAT_23eed8d30);
        local_98 = *(undefined1 (*) [8])PyExc_UnboundLocalError_exref;
        *(longlong *)local_98 = *(longlong *)local_98 + 1;
        local_88[0] = (code *)0x0;
        if (local_98 != (undefined1  [8])pcVar28) {
          FUN_23e91b1b0(param_1,local_98,local_98 + 8,local_88);
        }
        FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),pcStack_90);
        pcVar13 = pcStack_90;
        auVar26 = local_98;
        pcVar28 = local_88[0];
      }
      else {
        plVar16 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8b40);
        plVar15 = DAT_23eed97b0;
        if (plVar16 == (longlong *)0x0) {
LAB_23e77be18:
          pcVar28 = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          auVar26 = *(undefined1 (*) [8])(param_1 + 0x60);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          pcVar13 = *(code **)(param_1 + 0x68);
          goto LAB_23e77be34;
        }
        lVar20 = *(longlong *)(param_1 + 0x10);
        pcVar11 = *(code **)(lVar20 + 0xe20);
        if (pcVar11 == (code *)0x0) {
          pcVar11 = (code *)FUN_23e916a20(PyTuple_Type_exref,2);
        }
        else {
          lVar9 = *(longlong *)(pcVar11 + 0x18);
          *(int *)(lVar20 + 0xebc) = *(int *)(lVar20 + 0xebc) + -1;
          *(longlong *)(lVar20 + 0xe20) = lVar9;
          *(longlong *)pcVar11 = 1;
        }
        pcVar13 = _PyRuntime_exref;
        *(longlong *)(pcVar11 + 0x20) = 0;
        lVar20 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar13 + 0x1f8) + 0x10) + 0x2e8);
        lVar9 = *(longlong *)(pcVar11 + -8);
        puVar3 = *(undefined8 **)(lVar20 + 8);
        *puVar3 = pcVar11 + -0x10;
        *(longlong *)(pcVar11 + -0x10) = lVar20;
        *(ulonglong *)(pcVar11 + -8) = (ulonglong)((uint)lVar9 & 3) | (ulonglong)puVar3;
        *(code **)(lVar20 + 8) = pcVar11 + -0x10;
        *plVar15 = *plVar15 + 1;
        *(longlong **)(pcVar11 + 0x18) = plVar15;
        uVar10 = DAT_23ed6cd28;
        if (DAT_23ed6a4c0 == (code *)0x0) {
          pcVar12 = (code *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
          if (pcVar12 != (code *)0x0) {
            *(longlong *)pcVar12 = *(longlong *)pcVar12 + 1;
            DAT_23ed6a4c0 = pcVar12;
            goto LAB_23e77b951;
          }
          PyErr_PrintEx(0);
          Py_Exit(1);
          pcVar13 = pcVar24;
LAB_23e77baf0:
          lVar20 = *(longlong *)(pcVar11 + 0x158);
          pcVar24 = pcVar13;
          if (lVar20 != 0) {
            if (*(longlong *)(lVar20 + 0x10) < 1) goto LAB_23e77b4ad;
            lVar9 = 0;
            while (pcVar12 != *(code **)(lVar20 + 0x18 + lVar9 * 8)) {
              lVar9 = lVar9 + 1;
              if (*(longlong *)(lVar20 + 0x10) == lVar9) goto LAB_23e77b4ad;
            }
            goto LAB_23e77b878;
          }
          do {
            if (pcVar12 == pcVar11) goto LAB_23e77b878;
            pcVar11 = *(code **)(pcVar11 + 0x100);
          } while (pcVar11 != (code *)0x0);
          if (pcVar12 == PyBaseObject_Type_exref) goto LAB_23e77b878;
          goto LAB_23e77b4ad;
        }
LAB_23e77b951:
        uStack_e0 = uVar10;
        local_e8 = pcVar24;
        lVar20 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_e8);
        if (lVar20 != 0) {
          *(longlong *)(pcVar11 + 0x20) = lVar20;
          plVar15 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,pcVar11);
          *(longlong *)pcVar11 = *(longlong *)pcVar11 + -1;
          if (*(longlong *)pcVar11 == 0) {
            (**(code **)(*(longlong *)(pcVar11 + 8) + 0x30))(pcVar11);
          }
          if (plVar15 == (longlong *)0x0) {
            local_98 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcStack_90 = *(code **)(param_1 + 0x68);
            local_88[0] = *(code **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *plVar16 = *plVar16 + -1;
            pcVar13 = pcStack_90;
            auVar26 = local_98;
            pcVar28 = local_88[0];
            if (*plVar16 == 0) {
              (**(code **)(plVar16[1] + 0x30))(plVar16);
              pcVar13 = pcStack_90;
              auVar26 = local_98;
              pcVar28 = local_88[0];
            }
            goto LAB_23e77be34;
          }
          *(undefined4 *)(plVar2 + 5) = 0x647;
          plVar17 = (longlong *)FUN_23e914090(param_1,plVar16);
          *plVar16 = *plVar16 + -1;
          if (*plVar16 == 0) {
            (**(code **)(plVar16[1] + 0x30))(plVar16);
          }
          *plVar15 = *plVar15 + -1;
          if (*plVar15 == 0) {
            (**(code **)(plVar15[1] + 0x30))(plVar15);
          }
          if (plVar17 == (longlong *)0x0) goto LAB_23e77be18;
          *plVar17 = *plVar17 + -1;
          if (*plVar17 == 0) {
            (**(code **)(plVar17[1] + 0x30))(plVar17);
          }
          *(longlong *)pcVar24 = *(longlong *)pcVar24 + -1;
          if (*(longlong *)pcVar24 == 0) {
            (**(code **)(*(longlong *)(pcVar24 + 8) + 0x30))(pcVar24);
          }
          plVar2 = *(longlong **)(param_1 + 0x138);
          *(longlong **)(param_1 + 0x138) = plVar14;
          if ((plVar2 != (longlong *)0x0) && (*plVar2 = *plVar2 + -1, *plVar2 == 0)) {
            (**(code **)(plVar2[1] + 0x30))();
          }
          goto LAB_23e77b090;
        }
        local_98 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_90 = *(code **)(param_1 + 0x68);
        local_88[0] = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar16 = *plVar16 + -1;
        if (*plVar16 == 0) {
          (**(code **)(plVar16[1] + 0x30))(plVar16);
        }
        *(longlong *)pcVar11 = *(longlong *)pcVar11 + -1;
        pcVar13 = pcStack_90;
        auVar26 = local_98;
        pcVar28 = local_88[0];
        if (*(longlong *)pcVar11 == 0) {
          (**(code **)(*(longlong *)(pcVar11 + 8) + 0x30))(pcVar11);
          pcVar13 = pcStack_90;
          auVar26 = local_98;
          pcVar28 = local_88[0];
        }
      }
LAB_23e77be34:
      local_88[0] = (code *)0x0;
      _local_98 = (undefined1  [16])0x0;
      *(longlong *)pcVar24 = *(longlong *)pcVar24 + -1;
      if (*(longlong *)pcVar24 == 0) {
        (**(code **)(*(longlong *)(pcVar24 + 8) + 0x30))(pcVar24);
      }
      pcVar12 = *(code **)(param_1 + 0x138);
      iVar6 = 0x647;
      goto LAB_23e77be84;
    }
    pcVar24 = *(code **)(pcVar11 + 8);
    if ((*(uint *)(pcVar24 + 0xa8) & 0x40000000) == 0) {
      if (((int)*(uint *)(pcVar24 + 0xa8) < 0) && (((byte)pcVar11[0xab] & 0x40) != 0))
      goto LAB_23e77baf0;
    }
    else {
      pcVar11 = pcVar24;
      if (*(int *)(*(longlong *)(pcVar24 + 8) + 0xa8) < 0) goto LAB_23e77baf0;
    }
    pcVar24 = pcVar13;
    if (pcVar12 == pcVar11) goto LAB_23e77b878;
  }
  else {
    lVar20 = *(longlong *)(pcVar12 + 0x10);
    if (0 < lVar20) {
      lVar9 = 0;
      do {
        if ((-1 < *(int *)(*(longlong *)(*(longlong *)(pcVar12 + lVar9 * 8 + 0x18) + 8) + 0xa8)) ||
           ((*(byte *)(*(longlong *)(pcVar12 + lVar9 * 8 + 0x18) + 0xab) & 0x40) == 0))
        goto LAB_23e77b800;
        lVar9 = lVar9 + 1;
      } while (lVar20 != lVar9);
      lVar9 = 0;
      do {
        iVar6 = FUN_23a35ebd0(param_1,pcVar11);
        if (iVar6 != 0) goto LAB_23e77b871;
        lVar9 = lVar9 + 1;
      } while (lVar20 != lVar9);
      pcVar13 = *(code **)(param_1 + 0x138);
    }
  }
LAB_23e77b4ad:
  pcStack_90 = pcVar13;
  if ((pcVar13 == (code *)0x0) || (pcVar13 == pcVar28)) {
    pcVar28 = (code *)0x0;
    auVar26 = *(undefined1 (*) [8])PyExc_RuntimeError_exref;
    pcVar13 = (code *)PyUnicode_FromString("No active exception to reraise");
    pcVar12 = *(code **)(param_1 + 0x138);
    iVar6 = 0x63a;
    *(longlong *)auVar26 = *(longlong *)auVar26 + 1;
LAB_23e77be84:
    *(longlong **)(param_1 + 0x138) = plVar14;
    if (pcVar12 != (code *)0x0) goto LAB_23e77b530;
    pcStack_90 = pcVar13;
    local_98 = auVar26;
    local_88[0] = pcVar28;
    if (pcVar28 == (code *)0x0) goto LAB_23e77bed2;
LAB_23e77b586:
    pcVar13 = DAT_23ed6a4f8;
    if (*(longlong **)(pcVar28 + 0x18) == plVar2) goto LAB_23e77b641;
    if (iVar6 == 0) {
      iVar6 = (int)plVar2[5];
    }
    local_88[0] = pcVar28;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar13 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar12 = *(code **)DAT_23ed6a4f8;
      *(undefined8 *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar12;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar12 = _PyRuntime_exref;
    *(longlong **)(pcVar13 + 0x18) = plVar2;
    *plVar2 = *plVar2 + 1;
    lVar20 = *(longlong *)(pcVar12 + 0x1f8);
    *(int *)(pcVar13 + 0x24) = iVar6;
    *(undefined4 *)(pcVar13 + 0x20) = 0xffffffff;
    lVar20 = *(longlong *)(*(longlong *)(lVar20 + 0x10) + 0x2e8);
    lVar9 = *(longlong *)(pcVar13 + -8);
    plVar14 = *(longlong **)(lVar20 + 8);
    *plVar14 = (longlong)(pcVar13 + -0x10);
    *(longlong *)(pcVar13 + -0x10) = lVar20;
    *(ulonglong *)(pcVar13 + -8) = (ulonglong)((uint)lVar9 & 3) | (ulonglong)plVar14;
    *(code **)(lVar20 + 8) = pcVar13 + -0x10;
    *(code **)(pcVar13 + 0x10) = pcVar28;
    *(longlong *)pcVar28 = *(longlong *)pcVar28 + 1;
    pcVar12 = local_88[0];
  }
  else {
    auVar26 = *(undefined1 (*) [8])(pcVar13 + 8);
    pcVar28 = *(code **)(pcVar13 + 0x28);
    *(longlong *)pcVar13 = *(longlong *)pcVar13 + 1;
    *(longlong *)auVar26 = *(longlong *)auVar26 + 1;
    pcVar12 = pcVar13;
    if (pcVar28 == (code *)0x0) {
      iVar6 = 0;
      *(longlong **)(param_1 + 0x138) = plVar14;
    }
    else {
      *(longlong *)pcVar28 = *(longlong *)pcVar28 + 1;
      if (*(longlong **)(pcVar28 + 0x18) == plVar2) {
        *(undefined4 *)(plVar2 + 5) = *(undefined4 *)(pcVar28 + 0x24);
      }
      iVar6 = 0;
      *(longlong **)(param_1 + 0x138) = plVar14;
    }
LAB_23e77b530:
    local_88[0] = (code *)0x0;
    _local_98 = (undefined1  [16])0x0;
    *(longlong *)pcVar12 = *(longlong *)pcVar12 + -1;
    if (*(longlong *)pcVar12 == 0) {
      (**(code **)(*(longlong *)(pcVar12 + 8) + 0x30))();
    }
    pcStack_90 = pcVar13;
    local_98 = auVar26;
    if (pcVar28 != (code *)0x0) goto LAB_23e77b586;
    local_88[0] = pcVar28;
    if (iVar6 == 0) {
      iVar6 = (int)plVar2[5];
    }
LAB_23e77bed2:
    pcVar13 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar13 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      pcVar12 = local_88[0];
    }
    else {
      pcVar28 = *(code **)DAT_23ed6a4f8;
      *(undefined8 *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar28;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      pcVar12 = (code *)0x0;
    }
    pcVar28 = _PyRuntime_exref;
    *(longlong *)(pcVar13 + 0x10) = 0;
    *(longlong **)(pcVar13 + 0x18) = plVar2;
    *plVar2 = *plVar2 + 1;
    lVar20 = *(longlong *)(pcVar28 + 0x1f8);
    *(int *)(pcVar13 + 0x24) = iVar6;
    lVar20 = *(longlong *)(lVar20 + 0x10);
    *(undefined4 *)(pcVar13 + 0x20) = 0xffffffff;
    lVar20 = *(longlong *)(lVar20 + 0x2e8);
    lVar9 = *(longlong *)(pcVar13 + -8);
    plVar14 = *(longlong **)(lVar20 + 8);
    *plVar14 = (longlong)(pcVar13 + -0x10);
    *(longlong *)(pcVar13 + -0x10) = lVar20;
    *(ulonglong *)(pcVar13 + -8) = (ulonglong)((uint)lVar9 & 3) | (ulonglong)plVar14;
    *(code **)(lVar20 + 8) = pcVar13 + -0x10;
  }
  pcVar28 = pcVar13;
  if ((pcVar12 != (code *)0x0) &&
     (*(longlong *)pcVar12 = *(longlong *)pcVar12 + -1, *(longlong *)pcVar12 == 0)) {
    (**(code **)(*(longlong *)(pcVar12 + 8) + 0x30))();
  }
LAB_23e77b641:
  local_88[0] = pcVar28;
  FUN_23e8bba40(plVar2,"oooooooo",plVar1,plVar8,local_140,plVar7,plVar23,local_130,local_138,0);
  if (DAT_23eedad30 == plVar2) {
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))(plVar2);
    }
    DAT_23eedad30 = (longlong *)0x0;
  }
  lVar20 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar2 = *(longlong **)(lVar20 + 0x28);
  plVar14 = (longlong *)plVar2[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar20 + 0x30);
  *(undefined4 *)(plVar2 + 8) = 0xffffffff;
  if (plVar14 != (longlong *)0x0) {
    plVar2[2] = 0;
    *plVar14 = *plVar14 + -1;
    if (*plVar14 == 0) {
      (**(code **)(plVar14[1] + 0x30))();
    }
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  pcVar13 = local_88[0];
  plVar2[0xf] = 0;
  auVar26 = local_98;
  pcVar28 = pcStack_90;
  _local_98 = (undefined1  [16])0x0;
  local_88[0] = (code *)0x0;
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if ((local_140 != (longlong *)0x0) &&
     (lVar20 = *local_140, *local_140 = lVar20 + -1, lVar20 + -1 == 0)) {
    (**(code **)(local_140[1] + 0x30))(local_140);
  }
  if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  if ((plVar23 != (longlong *)0x0) && (*plVar23 = *plVar23 + -1, *plVar23 == 0)) {
    (**(code **)(plVar23[1] + 0x30))(plVar23);
  }
  if ((local_130 != (longlong *)0x0) &&
     (lVar20 = *local_130, *local_130 = lVar20 + -1, lVar20 + -1 == 0)) {
    (**(code **)(local_130[1] + 0x30))(local_130);
  }
  if ((local_138 != (longlong *)0x0) &&
     (lVar20 = *local_138, *local_138 = lVar20 + -1, lVar20 + -1 == 0)) {
    (**(code **)(local_138[1] + 0x30))(local_138);
  }
  *plVar1 = *plVar1 + -1;
  local_88[0] = pcVar13;
  local_98 = auVar26;
  pcStack_90 = pcVar28;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,local_98,pcStack_90,local_88[0]);
  return (code *)0x0;
}
